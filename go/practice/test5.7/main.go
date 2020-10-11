//使startElement支持注释、标签属性、文本节点
package main

import (
	"fmt"
	"golang.org/x/net/html"
	"net/http"
	"os"
)

var depth int

func main() {
	//for _, url := range os.Args[1:] {
	//	err := outline(url)
	//	if err != nil {
	//		fmt.Printf("err : %v\n", err)
	//		os.Exit(1)
	//	}
	//}

	doc, err := html.Parse(os.Stdin)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	foreachNode(doc, startElement, endElement)
}

func outline(url string) error {
	resp, err := http.Get(url)
	if err != nil {
		return err
	}
	defer resp.Body.Close()
	doc, err := html.Parse(resp.Body)
	if err != nil {
		return err
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

func startElement(n *html.Node) {
	switch n.Type {
	case html.ElementNode:
		fmt.Printf("%*s<%s", depth * 2, "", n.Data)
		for _, a := range n.Attr {
			fmt.Printf(" %s=%q ", a.Key, a.Val)
		}
		if n.Data == "img" && n.FirstChild == nil {
			fmt.Printf("/>\n")
		} else {
			fmt.Printf(">\n")
		}
		depth++
	case html.CommentNode://注释节点
		fmt.Printf("%*s<!--%s-->\n", depth * 2, "", n.Data)
	}
}

func endElement(n *html.Node) {
	if n.Type == html.ElementNode {
		depth--
		if n.Data != "img" || n.FirstChild != nil {
			fmt.Printf("%*s</%s>\n", depth * 2, "",n.Data)
		}
	}
}
