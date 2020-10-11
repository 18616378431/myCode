package main

import (
	"bufio"
	"fmt"
	"os"
)

type line struct {
	FileName string
	Text string
}

func main() {
	counts := make(map[line]int)
	files := os.Args[1:]
	if len(files) == 0 {
		countsLines(os.Stdin, counts, "args")
	} else {
		for _,arg := range files {
			f,err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup2 : %v\n", err)
				continue
			}
			countsLines(f, counts, f.Name())
			f.Close()
		}
	}

	for line,n := range counts {
		if n > 1 {
			fmt.Printf("%s\t%d\t%s\n", line.FileName, n, line.Text)
		}
	}
}

func countsLines(f *os.File, counts map[line] int, FileName string) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		counts[line{FileName, input.Text()}]++
	}
}
