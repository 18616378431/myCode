package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	s := "+1234.5678"
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
	start := ""
	if strings.HasPrefix(s, "-") || strings.HasPrefix(s, "+") {
		start = string(s[0])
		s = s[1:]
	}

	end := ""
	if strings.Contains(s, ".") {
		ss := strings.Split(s, ".")
		s, end = ss[0], "." + ss[1]
	}
	l := len(s)

	mod := l % 3
	if mod > 0 && l > 3 {
		r.Write([]byte(s[:mod] + ","))
	}
	for mod + 3 < l {
		r.Write([]byte(s[mod:mod + 3] + ","))
		mod += 3
	}
	if mod + 3 == l {
		r.Write([]byte(s[mod:mod + 3]))
	}
	return strings.Join([]string{start, r.String(), end}, "")
}
