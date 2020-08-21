package main

import (
	"fmt"
	"gopl.io/ch5/links"
	"log"
	"os"
)

func main() {
	worklist := make(chan []string)
	var n int

	n++
	go func() {
		worklist <- os.Args[1:]
	}()

	//并发爬取web
	seen := make(map[string]bool)

	for ; n > 0; n-- {
		list := <- worklist
		for _, link := range list {
			if !seen[link] {
				seen[link] = true
				n++
				go func(link string) {
					worklist <- crawl2(link)
				}(link)
			}
		}
	}

	//for list := range worklist {
	//	for _, link := range list {
	//		if !seen[link] {
	//			seen[link] = true
	//			go func(link string) {
	//				//worklist <- crawl1(link)
	//				worklist <- crawl2(link)
	//			}(link)
	//		}
	//	}
	//}
}

func crawl1(url string) []string {
	fmt.Println(url)
	list, err := links.Extract(url)
	if err != nil {
		log.Print(err)
	}
	return list
}

var tokens = make(chan struct{}, 20)

func crawl2(url string) []string {
	fmt.Println(url)
	tokens <- struct{}{}//获取令牌
	list, err := links.Extract(url)
	<- tokens//释放令牌
	if err != nil {
		log.Print(err)
	}
	return list
}