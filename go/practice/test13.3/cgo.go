/**
md5sum < /usr/share/dict/words
./test13.3 < /usr/share/dict/words | wc -c
 wc -c /usr/share/dict/words
./test13.3 < /usr/share/dict/words | bunzip2 | wc -c
./test13.3 < /usr/share/dict/words | bunzip2 | md5sum
 */
package main

import (
	"io"
	"log"
	"os"
	"sync"
	"unsafe"
)

/*
#cgo CFLAGS:-I/usr/local/opt/bzip2/include
#cgo LDFLAGS:-L/usr/local/opt/bzip2/lib -lbz2
#include <bzlib.h>
int bz2compress(bz_stream *s, int action, char *in, unsigned *inlen, char *out, unsigned *outlen);

#include <stdlib.h>

bz_stream* bz2alloc() {
	return calloc(1, sizeof(bz_stream));
}

void bz2free(bz_stream* s) {
	free(s);
}
 */
import "C"

type writer struct {
	w io.Writer//输出流
	stream *C.bz_stream
	outbuf [64 * 1024]byte
	sync.Mutex
}

//返回writer
func NewWriter(out io.Writer) io.WriteCloser {
	const (
		blocksize = 9
		verbosity = 0
		workFactor = 30
	)
	w := &writer{w : out, stream : C.bz2alloc()}
	C.BZ2_bzCompressInit(w.stream, blocksize, verbosity, workFactor)
	return w
}

func (w *writer) Write(data []byte) (int, error) {
	if w.stream == nil {
		panic("closed")
	}
	w.Lock()
	defer w.Unlock()
	var total int//写入的未压缩字节
	for len(data) > 0 {
		inlen, outlen := C.uint(len(data)), C.uint(cap(w.outbuf))
		C.bz2compress(w.stream, C.BZ_RUN,
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
	w.Lock()
	defer func() {
		C.BZ2_bzCompressEnd(w.stream)
		C.bz2free(w.stream)
		w.stream = nil
		w.Unlock()
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

func main() {
	w := NewWriter(os.Stdout)
	if _, err := io.Copy(w, os.Stdin); err != nil {
		log.Fatalf("bzipper : %v\n", err)
	}
	if err := w.Close(); err != nil {
		log.Fatalf("bzipper : close : %v\n", err)
	}
}