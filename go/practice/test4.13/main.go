package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"net/url"
	"os"
	"strings"
	"sync"
)

const (
	apiKey = "837a1b8b"
	apiUrl = "http://www.omdbapi.com/"
)

type movieInfo struct {
	Title string
	Year string
	Poster string
}

func GetPoster(name string) {
	resp, err := http.Get(fmt.Sprintf("%s?t=%s&apikey=%s", apiUrl, url.QueryEscape(name), apiKey))
	if err != nil {
		fmt.Printf("Get err : %s\n", err)
		return
	}
	defer resp.Body.Close()
	binfo, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Printf("ReadAll err : %s\n", err)
		return
	}
	minfo := movieInfo{}
	err = json.Unmarshal(binfo, &minfo)
	if err != nil {
		fmt.Printf("json err : %s\n", err)
		return
	}
	poster := minfo.Poster
	if poster != "" {
		downloadPoster(poster)
	}
}

func downloadPoster(url string) {
	resp, err := http.Get(url)
	if err != nil {
		fmt.Printf("Http Err : %s\n", err)
		return
	}
	defer resp.Body.Close()
	bcontent, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Printf("ReadAll err : %s\n", err)
		return
	}
	pos := strings.LastIndex(url, "/")
	if pos == -1 {
		fmt.Printf("LastIndex err : fail to get file name!")
		return
	}
	f, err := os.Create(url[pos + 1:])
	if err != nil {
		fmt.Printf("create fail : %s\n", err)
		return
	}
	defer f.Close()
	_, err = f.Write(bcontent)
	if err != nil {
		fmt.Printf("File Write fail : %s\n", err)
	}
}

func main() {
	var wg sync.WaitGroup
	names := os.Args[1:]
	for _, name := range names {
		wg.Add(1)
		go func() {
			GetPoster(name)
			wg.Done()
		}()
	}
	wg.Wait()
}
