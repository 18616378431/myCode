package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"unicode"
)

func main() {
	seen := make(map[rune]bool)
	var (
		letterCount,
		numberCount,
		otherCount,
		invalid int
	)
	in := bufio.NewReader(os.Stdin)
	for {
		r, n, err := in.ReadRune()
		if err == io.EOF {
			break
		}
		if err != nil {
			fmt.Fprintln(os.Stderr, "charcount : %v\n", err)
			os.Exit(1)
		}
		if r == unicode.ReplacementChar && n == 1 {
			invalid++
			continue
		}
		if unicode.IsLetter(r) && !seen[r] {
			letterCount++
			seen[r] = true
			continue
		}
		if unicode.IsNumber(r) && !seen[r] {
			numberCount++
			seen[r] = true
			continue
		}
		if !seen[r] {
			otherCount++
			seen[r] = true
		}
	}
	fmt.Fprintf(os.Stdout, "letterCount:%d\tnumberCount:%d\totherCount:%d\tinvalid:%d\n",
			letterCount, numberCount, otherCount, invalid)
}
