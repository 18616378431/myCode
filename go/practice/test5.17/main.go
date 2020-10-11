//变长函数取html节点名字
package main

import (
	"fmt"
	"golang.org/x/net/html"
	"os"
)

func main() {
	doc, err := html.Parse(os.Stdin)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	nodes := ElementsByTagName(doc, "a", "img")
	for _, n := range nodes {
		fmt.Println(n.Data)
		fmt.Println(n.Attr)
	}
}

func ElementsByTagName(doc *html.Node, name ...string) []*html.Node {
	var nodes []*html.Node
	if doc.Type == html.ElementNode {
		for _, data := range name {
			if doc.Data == data {
				nodes = append(nodes, doc)
			}
		}
	}
	for c := doc.FirstChild; c != nil; c = c.NextSibling {
		nodes = append(nodes, ElementsByTagName(c, name...)...)
	}
	return nodes
}
