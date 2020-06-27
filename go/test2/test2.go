package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	var s, sep string

	for i := 0; i < len(os.Args); i++ {
		s += sep + os.Args[i]
		sep = " "
	}
	fmt.Println(s)

	var s1, sep1 = "", ""
	for idx, arg := range os.Args[0:] {
		s1 += sep1 + arg
		sep1 = " "
		fmt.Println(idx, arg)
	}
	fmt.Println(s1)

	fmt.Println(strings.Join(os.Args[0:], " "))

	fmt.Println("Hello World!")
}
