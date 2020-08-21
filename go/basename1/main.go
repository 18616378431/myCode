package main

import (
	"fmt"
	"os"
)

func main() {
	var args = os.Args

	fmt.Printf("v : %s\n", basename(args[1]))
}

func basename(s string) string {
	//将最后一个斜杠之前的部分全部舍弃
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '/' {
			s = s[i + 1:]
			break
		}
	}
	//保留最后一个点之前的所有内容
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '.' {
			s = s[:i]
			break
		}
	}

	return s
}
