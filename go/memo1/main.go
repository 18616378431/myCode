package main

import (
	"fmt"
	"gopl.io/ch9/memo5"
	"io/ioutil"
	"log"
	"net/http"
	"sync"
	"time"
)

//函数记忆,并发非阻塞缓存

func httpGetBody(url string) (interface{}, error) {
	resp, err := http.Get(url)
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	return ioutil.ReadAll(resp.Body)
}

func main() {
	m := memo5.New(httpGetBody)
	var n sync.WaitGroup

	for url := range incomingURLs() {
		n.Add(1)
		go func(url string) {
			start := time.Now()
			value, err := m.Get(url)
			if err != nil {
				log.Print(err)
			}
			fmt.Printf("%s, %s, %d bytes\n", url, time.Since(start), len(value.([]byte)))
			n.Done()
		}(url)
	}

	for url := range incomingURLs() {
		n.Add(1)
		go func(url string) {
			start := time.Now()
			value, err := m.Get(url)
			if err != nil {
				log.Print(err)
			}
			fmt.Printf("%s, %s, %d bytes\n", url, time.Since(start), len(value.([]byte)))
			n.Done()
		}(url)
	}

	n.Wait()
}

func incomingURLs() map[string]bool {
	str := make(map[string]bool)
	str["https://www.baidu.com"] = true
	str["https://www.csdn.net"] = true
	return str
}
