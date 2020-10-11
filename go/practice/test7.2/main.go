package main

import (
	"fmt"
	"io"
	"io/ioutil"
)

func main() {
	w, c := CountingWriter(ioutil.Discard)
	fmt.Fprintf(w, "Hello World!")
	fmt.Println(*c)
}

type ByteCounter struct {
	w io.Writer
	written int64
}

func (b *ByteCounter) Write(p []byte) (int, error) {
	n, err := b.w.Write(p)
	b.written += int64(n)
	return n, err
}

func CountingWriter(w io.Writer) (io.Writer, *int64) {
	c := ByteCounter{w, 0}
	return &c, &c.written
}
