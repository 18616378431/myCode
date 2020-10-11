package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	fmt.Println(math.Hypot(3, 4))

	file, err := os.Open("testmath")

	if err != nil {
		panic(err)
	}


	fi, err := file.Stat()

	if err != nil {
		panic(err)
	}

	fmt.Println(fi.Size())
}