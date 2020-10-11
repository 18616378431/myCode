//使startElement支持注释、标签属性、文本节点
//./test5.8 < test.html  -id mmm
package main

import (
	"flag"
	"fmt"
	"golang.org/x/net/html"
	"os"
)

var id = flag.String("id", "", "element id")

func main() {
	//for _, url := range os.Args[1:] {
	//	err := outline(url)
	//	if err != nil {
	//		fmt.Printf("err : %v\n", err)
	//		os.Exit(1)
	//	}
	//}

	flag.Parse()

	doc, err := html.Parse(os.Stdin)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	if node := ElementById(doc, *id); node == nil {
		fmt.Printf("Element Not Found!")
		os.Exit(1)
	} else {
		fmt.Println(node.Data)
		for _, a := range node.Attr {
			fmt.Printf("%s=%q\n", a.Key, a.Val)
		}
	}

}

func ElementById(doc *html.Node, id string) *html.Node {
	return foreachNode(doc, id, findElement, findElement)
}

func foreachNode(n *html.Node, id string, pre, post func(n *html.Node, id string) bool) *html.Node  {
	if pre != nil {
		if !pre(n, id) {
			return n
		}
	}
	for c := n.FirstChild; c != nil; c = c.NextSibling {
		if node := foreachNode(c, id, pre, post); node != nil {
			return node
		}
	}
	if post != nil {
		if !post(n, id) {
			return n
		}
	}
	return nil
}

//false Find,true not find
func findElement(n *html.Node, id string) bool {
	if n.Type == html.ElementNode {
		for _, a := range n.Attr {
			if a.Key == "id" && a.Val == id {
				return false
			}
		}
	}
	return true
}
