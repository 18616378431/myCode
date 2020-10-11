package main

import (
	"bytes"
	"fmt"
)

func main() {
	s := "1234"
	fmt.Printf("%s\n", comma1(s))
}

func comma(s string) string {
	n := len(s)

	if n <= 3 {
		return s
	}

	return comma(s[:n - 3]) + "," + s[n - 3 :]
}

func comma1(s string) string {
	var r bytes.Buffer
	l := len(s)
	if l < 3 {
		return s
	}
	mod := l % 3
	if mod > 0 {
		r.Write([]byte(s[:mod] + ","))
	}
	for mod + 3 < l {
		r.Write([]byte(s[mod:mod + 3] + ","))
		mod += 3
	}
	if mod + 3 == l {
		r.Write([]byte(s[mod:mod + 3]))
	}
	return r.String()
}
