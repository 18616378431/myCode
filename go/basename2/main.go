package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	fmt.Printf("%s\n", basename(os.Args[1]))
}

func basename(s string) string {
	slash := strings.LastIndex(s, "/")//未找到斜杠slash = -1
	s = s[slash + 1:]
	if dot := strings.LastIndex(s, "."); dot >=0 {
		s = s[:dot]
	}

	return s
}
