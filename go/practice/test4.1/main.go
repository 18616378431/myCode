package main

import (
	"crypto/sha256"
	"fmt"
)

func main() {
	b := sha256.Sum256([]byte("x"))
	fmt.Println(PopCount(b))
}

func PopCount(b [32]byte) int {
	var res int
	for _, v := range b {
		n := int(v)
		for n > 0 {
			n = n & (n - 1)
			res++
		}
	}
	return res
}