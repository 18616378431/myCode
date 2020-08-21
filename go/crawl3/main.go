package main

import (
	"fmt"
	"gopl.io/ch5/links"
	"log"
	"os"
)

func main() {
	worklist := make(chan []string)//可能有重复的url列表
	unseenLinks := make(chan string)//去重后的url列表

	go func() {
		worklist <- os.Args[1:]
	}()

	//创建20个协程
	for i := 0; i < 20; i++ {
		go func() {
			for link := range unseenLinks {
				foundLinks := crawl1(link)
				go func() {
					worklist <- foundLinks
				}()
			}
		}()
	}

	//主goroutine队url去重
	seen := make(map[string]bool)
	for list := range worklist {
		for _, link := range list {
			if !seen[link] {
				seen[link] = true
				unseenLinks <- link
			}
		}
	}
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