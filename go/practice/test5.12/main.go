package main

import (
	"fmt"
	"golang.org/x/net/html"
	"log"
	"os"
)

func main() {
	err := outline()
	if err != nil {
		log.Println(err)
	}
}

func outline() error {
	doc, err := html.Parse(os.Stdin)
	if err != nil {
		return err
	}
	var depth int
	startElement := func(n *html.Node) {
		if n.Type == html.ElementNode {
			fmt.Printf("%*s<%s>\n", depth * 2, "", n.Data)
			depth++
		}
	}
	endElement := func(n *html.Node) {
		if n.Type == html.ElementNode {
			depth--
			fmt.Printf("%*s</%s>\n", depth * 2, "", n.Data)
		}
	}

	foreachNode(doc, startElement, endElement)

	return nil
}

func foreachNode(n *html.Node, pre, post func(n *html.Node)) {
	if pre != nil {
		pre(n)
	}
	for c := n.FirstChild; c != nil; c = c.NextSibling {
		foreachNode(c, pre, post)
	}

	if post != nil {
		post(n)
	}
}
