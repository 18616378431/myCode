package main

// ./fetch https://www.w3.org/TR/2006/REC-xml11-20060816 >> test.xml

import (
	"encoding/xml"
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	dec := xml.NewDecoder(os.Stdin)
	var stack []string//元素名栈
	for {
		tok, err := dec.Token()
		if err == io.EOF {
			break
		} else if err != nil {
			fmt.Fprintf(os.Stderr, "xmlselect : %v\n", err)
			os.Exit(1)
		}
		switch tok := tok.(type) {
		case xml.StartElement:
			stack = append(stack, tok.Name.Local)
		case xml.EndElement:
			stack = stack[:len(stack) - 1]
		case xml.CharData:
			if containsAll(stack, os.Args[1:]) {
				fmt.Printf("%s : %s\n", strings.Join(stack, " "), tok)
			}
		}
	}
}

//判断栈中元素顺序是否包含给定顺序的标签
func containsAll(x, y []string) bool {
	for len(y) <= len(x) {
		if len(y) == 0 {
			return true
		}
		if x[0] == y[0] {
			y = y[1:]
		}
		x = x[1:]
	}
	return false
}