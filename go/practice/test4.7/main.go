package main

import (
	"fmt"
	"unicode/utf8"
)

func main() {
	b := []byte("北京欢迎您welcome")
	fmt.Printf("%s\n", b)
	fmt.Printf("%s\n", mbreverse(b))
}

func mbreverse(b []byte) []byte {
	var res []byte
	for i := len(b); i > 0; {
		r, size := utf8.DecodeLastRune(b[:i])
		res = append(res, []byte(string(r))...)
		i -= size
	}
	return res
}