//统计html文档中所有元素的个数
package main

import (
	"fmt"
	"golang.org/x/net/html"
	"os"
)

var count = make(map[string]int)

func main() {
	doc, err := html.Parse(os.Stdin)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Html Node count : %v\n", err)
		os.Exit(1)
	}
	visit(doc)

	for t, c := range count {
		fmt.Println(t, c)
	}
}

func visit(n *html.Node) {
	if n.Type == html.ElementNode {
		count[n.Data]++
	}
	for c := n.FirstChild; c != nil; c = c.NextSibling {
		visit(c)
	}
}
