package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	words := wordfreq()
	for w, n := range words {
		fmt.Printf("%s\t%d\n", w, n)
	}
}

//统计文本中单词出现的次数
func wordfreq() map[string]int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	words := make(map[string]int)
	for scanner.Scan() {
		words[scanner.Text()]++
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, err)
	}
	return words
}