package main

import (
	"fmt"
	"golang.org/x/net/html"
	"io"
	"os"
)

func main() {
	doc, err := html.Parse(NewReader("<h1>Hello</h1>"))
	if err != nil {
		fmt.Fprintf(os.Stderr, "html parse error : %s\n", err)
		os.Exit(1)
	}
	fmt.Println(doc.Type)
	fmt.Println(html.ElementNode)
}

type StringReader string

func (s *StringReader) Read(p []byte) (int, error) {
	copy(p, *s)
	return len(*s), io.EOF
}

func NewReader(s string) io.Reader {
	str := StringReader(s)
	return &str
}
