package main

import (
	"fmt"
	"unicode"
	"unicode/utf8"
)

func main() {
	b := []byte("北京\t欢迎\n您")
	fmt.Printf("%s\n%v\n", b, b)
	ex4_6(b)
	fmt.Printf("%s\n%v\n", b, b)
}

func ex4_6(b []byte) []byte {
	var i int
	for i, l := 0, 0; l < len(b); {
		r, size := utf8.DecodeRune(b[i:])
		l += size
		if unicode.IsSpace(r) {
			if i > 0 && b[i - 1] == byte(32) {
				copy(b[i:], b[i + size:])
			} else {
				b[i] = byte(32)
				copy(b[i + 1:], b[i + size:])
				i++
			}
		} else {
			i += size
		}
	}
	return b[0:i]
}