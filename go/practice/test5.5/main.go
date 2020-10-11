//实现countWordAndImages 获取文档的字数与图片数
package main

import (
	"fmt"
	"golang.org/x/net/html"
	"net/http"
	"os"
	"strings"
)

func main() {
	words, images, err := CountWordsAndImages("https://www.csdn.net")
	if err != nil {
		fmt.Fprintf(os.Stderr, "err : %v\n", err)
		os.Exit(1)
	}
	fmt.Printf("words : %d, images : %d\n", words, images)
}


func CountWordsAndImages(url string) (words, images int, err error) {
	resp, err := http.Get(url)
	if err != nil {
		return
	}
	defer resp.Body.Close()
	doc, err := html.Parse(resp.Body)
	if err != nil {
		err = fmt.Errorf("parsing html err : %v\n", err)
		return
	}
	words, images = countWordsAndImages(doc)
	return
}

func countWordsAndImages(n *html.Node) (words, images int) {
	if n == nil {
		return
	}
	if n.Type == html.TextNode {
		words += len(strings.Fields(n.Data))
	}
	if n.Type == html.ElementNode && n.Data == "img" {
		images++
	}
	for c := n.FirstChild; c != nil; c = c.NextSibling {
		word1, images1 := countWordsAndImages(c)
		words += word1
		images += images1
	}
	return words, images
}