package main

import (
	"flag"
	"fmt"
	"gopl.io/ch5/links"
	"io"
	"log"
	"net/http"
	"os"
	"strings"
	"sync"
)

var base = flag.String("base", "https://www.csdn.net", "")

var token = make(chan struct{}, 20)
var downloadToken = make(chan struct{}, 20)

func main() {
	flag.Parse()

	worklist := make(chan []string)
	var n int

	n++
	go func() {
		worklist <- crawl(*base)
	}()

	seen := make(map[string]bool)

	for ; n > 0; n-- {
		list := <- worklist
		for _, link := range list {
			if !seen[link] {
				seen[link] = true
				n++

				go func(link string) {
					worklist <- crawl(link)
				}(link)

				wg.Add(1)
				url := link
				go func() {
					defer wg.Done()
					download(*base, url)
				}()
			}
		}
	}

	fmt.Println("download---------------------")

	//for us := range worklist {
	//	for _, url := range us {
	//		wg.Add(1)
	//		url := url
	//		go func() {
	//			defer wg.Done()
	//			download(*base, url)
	//		}()
	//	}
	//}

	done := make(chan struct{})
	go func() {
		wg.Wait()
		done <- struct{}{}
	}()
	<-done
}

var wg sync.WaitGroup

func download(base, url string) {
	fmt.Println("download----------------------------------------")
	downloadToken <- struct{}{}
	defer func() {
		<-downloadToken
	}()
	if !strings.HasPrefix(url, base) {
		fmt.Println("Download Not Prefix")
		return
	}

	resp, err := http.Get(url)
	if err != nil {
		log.Println(err)
		return
	}
	defer resp.Body.Close()

	dir := strings.TrimPrefix(strings.TrimPrefix(url, "http://"), "https://")
	if err := os.MkdirAll(dir, 0755); err != nil {
		log.Fatalln(err)
	}

	filename := dir + "/index.html"
	//filename := path.Base(dir)
	f, err := os.Create(filename)
	if err != nil {
		log.Fatalln(err)
	}
	defer f.Close()
	_, err = io.Copy(f, resp.Body)
	if err != nil {
		log.Fatalln(err)
	}
}

func crawl(url string) []string {
	//fmt.Println("crawl----------------------------------------")
	if !strings.HasPrefix(url, *base) {
		fmt.Println("Not Prefix")
		return nil
	}
	token <- struct{}{}
	list, err := links.Extract(url)
	<- token
	if err != nil {
		log.Print(err)
		return nil
	}
	return list
}
