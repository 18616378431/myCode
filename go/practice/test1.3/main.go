package main

import (
	"fmt"
	"os"
	"strings"
	"time"
)

func main() {
	//for
	a := time.Now()
	for i := 0; i < 10000; i++ {
		s, sep := "", ""
		for _, arg := range os.Args[0:] {
			s += sep + arg
			sep = " "
		}
		//fmt.Println(s)
	}
	fmt.Println(time.Since(a).Seconds())

	//strings.Join
	b := time.Now()
	for i := 0; i < 10000; i++ {
		strings.Join(os.Args[0:], " ")
		//fmt.Println(s)
	}
	fmt.Println(time.Since(b).Seconds())
}
