//广度优先遍历 保存页面到本地
package main

import (
	"flag"
	"gopl.io/ch5/links"
	"io"
	"log"
	"net/http"
	"os"
	"strings"
	"sync"
)

var wg sync.WaitGroup

var base = flag.String("base", "https://blog.csdn.net", "url")

func main() {
	flag.Parse()

	//fmt.Println(crawl(*base))
	//os.Exit(1)

	for _, url := range crawl(*base) {
		wg.Add(1)
		go download(*base, url)
	}
	done := make(chan struct{})

	go func() {
		wg.Wait()
		done <- struct{}{}
	}()
	<-done
}

func download(base, url string) {
	defer wg.Done()
	if !strings.HasPrefix(url, base) {
		return
	}
	resp, err := http.Get(url)
	if err != nil {
		log.Println(err)
		return
	}
	defer resp.Body.Close()
	dir := strings.TrimPrefix(strings.TrimPrefix(url, "http://"), "https://")
	if err := os.MkdirAll(dir, 0777); err != nil {
		log.Fatalln(err)
	}
	filename := dir + "index.html"
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
	list, err := links.Extract(url)
	if err != nil {
		log.Print(err)
	}
	return list
}
