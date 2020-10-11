package main

import (
	"fmt"
	"gopl.io/ch5/links1"
	"log"
	"os"
)

func crawl(url string, cancelled chan struct{}) []string {
	fmt.Println(url)
	list, err := links1.Extract(url, cancelled)
	if err != nil {
		log.Print(err)
	}
	return list
}

func main() {
	worklist := make(chan []string)
	unseenLinks := make(chan string)

	go func() {
		worklist <- os.Args[1:]
	}()

	cancelled := make(chan struct{})

	go func() {
		os.Stdin.Read(make([]byte, 1))
		close(cancelled)
	}()

	for i := 0; i < 20; i++ {
		go func() {
			for link := range unseenLinks {
				foundLinks := crawl(link, cancelled)
				go func() {
					worklist <- foundLinks
				}()
			}
		}()
	}

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
