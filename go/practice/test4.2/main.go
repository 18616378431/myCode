package main

import (
	"crypto/sha256"
	"crypto/sha512"
	"flag"
	"fmt"
	"os"
)

var t = flag.Int("t", 2, "-t 2|3|5")

func main() {
	flag.Parse()
	c := make([]byte, 1024)
	n, err := os.Stdin.Read(c)
	if err != nil {
		fmt.Println(err)
		return
	}

	switch *t {
	case 3:
		fmt.Printf("%x\n", sha512.Sum384(c[0:n]))
	case 5:
		fmt.Printf("%x\n", sha512.Sum512(c[0:n]))
	default:
		fmt.Printf("%x\n", sha256.Sum256(c[0:n]))
	}
}
