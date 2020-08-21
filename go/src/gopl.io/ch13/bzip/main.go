package bzip

/*
#cgo CFLAGS: -I/usr/include
#cgo LDFALGS: -L/usr/lib -lbz2
#include <bz2lib.h>
int bz2compress(bz_stream *s, int action, char *in, unsigned *inlen, char *out, unsigned *outlen);
 */

import "C"
import (
	"io"
	"unsafe"
)

type writer struct {
	w io.Writer//输出流
	stream *C.bz_stream
	outbuf [64 * 1024]byte
}

//返回writer
func NewWriter(out io.Writer) io.WriteCloser {
	const (
		blocksize = 9
		verbosity = 0
		workFactor = 30
	)
	w := &writer{w : out, stream : C.bz2alloc()}
	C.BZ_bzCompressInit(w.stream, blocksize, verbosity, workFactor)
	return w
}

func (w *writer) Write(data []byte) (int, error) {
	if w.stream == nil {
		panic("closed")
	}
	var total int//写入的未压缩字节
	for len(data) > 0 {
		inlen, outlen := C.uint(len(data)), C.uint(cap(w.outbuf))
		C.bzcompress(w.stream, C.BZ_RUN,
			(*C.char)(unsafe.Pointer(&data[0])), &inlen,
			(*C.char)(unsafe.Pointer(&w.outbuf)), &outlen)
		total += int(inlen)
		data = data[inlen:]
		if _, err := w.w.Write(w.outbuf[:outlen]); err != nil {
			return total, err
		}
	}
	return total, nil
}

func (w *writer) Close() error {
	if w.stream == nil {
		panic("closed")
	}
	defer func() {
		C.BZ2_bzCompressEnd(w.stream)
		C.bz2free(w.stream)
		w.stream = nil
	}()
	for {
		inlen, outlen := C.uint(0), C.uint(cap(w.outbuf))
		r := C.bz2compress(w.stream, C.BZ_FINISH,
			nil, &inlen,
			(*C.char)(unsafe.Pointer(&w.outbuf)), &outlen)
		if _, err := w.w.Write(w.outbuf[:outlen]); err != nil {
			return err
		}
		if r == C.BZ_STREAM_END {
			return nil
		}
	}
}
