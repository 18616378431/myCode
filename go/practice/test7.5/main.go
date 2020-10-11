package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"strings"
)

func main() {
	lr := LimitReader(strings.NewReader("123456"), 2)
	b, err := ioutil.ReadAll(lr)
	if err != nil {
		fmt.Fprintf(os.Stderr, "err : %v\n", err)
		os.Exit(1)
	}
	fmt.Printf("%s\n", b)

	b, err = ioutil.ReadAll(lr)
	fmt.Println(b)
}

type LimitedReader struct {
	underlyingReader io.Reader
	remainBytes int64
}

func (lr *LimitedReader) Read(p []byte) (int, error) {
	if lr.remainBytes <= 0 {
		return 0, io.EOF
	}
	if int64(len(p)) > lr.remainBytes {
		p = p[:lr.remainBytes]
	}
	n, err := lr.underlyingReader.Read(p)
	lr.remainBytes -= int64(n)
	return n, err
}

func LimitReader(r io.Reader, n int64) io.Reader {
	return &LimitedReader{r, n}
}
