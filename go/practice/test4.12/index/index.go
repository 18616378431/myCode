package index

import (
	"crypto/tls"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"strings"
	"sync"
)

const MaxNum = 20
const XkcdUrl = "https://xkcd.com"
const IndexDir = "../tmp/db.json"

var wg sync.WaitGroup
var limiter = make(chan struct{}, 20)

type XkcdDb []XkcdInfo

type XkcdInfo struct {
	Month string
	Num int
	Link string
	Year string
	News string
	SafeTitle string `json:"safe_title"`
	Transcript string
	Alt string
	Img string
	Title string
	Day string
}

var initSync sync.Once
var db XkcdDb

func init() {
	initSync.Do(func() {
		content, err := ioutil.ReadFile(IndexDir)
		if err != nil {
			panic(err)
		}
		err = json.Unmarshal(content, &db)
		if err != nil {
			panic(err)
		}
	})
}

func BuildIndex() {
	db := make(XkcdDb, MaxNum + 1)
	ch := make(chan *XkcdInfo, MaxNum)
	for i := 1; i <= MaxNum; i++ {
		wg.Add(1)
		go GetIndex(i, ch)
	}
	go func() {
		for v := range ch {
			fmt.Println(v.Num)
			db[v.Num] = *v
		}
	}()
	wg.Wait()
	close(ch)

	sdb, err := json.Marshal(db)
	if err != nil {
		fmt.Println(err)
		return
	}
	err = ioutil.WriteFile(IndexDir, sdb, os.ModePerm)
	if err != nil {
		fmt.Println(err)
	}
}

func GetIndex(num int, ch chan *XkcdInfo) {
	limiter <- struct{}{}
	defer wg.Done()
	defer func() {
		<- limiter
	}()
	url := fmt.Sprintf("%s/%d/info.0.json", XkcdUrl, num)
	tr := &http.Transport{TLSClientConfig : &tls.Config{InsecureSkipVerify : true}}
	client := &http.Client{Transport : tr}
	resp, err := client.Get(url)
	if err != nil {
		fmt.Println(url, err)
		return
	}
	defer resp.Body.Close()
	if resp.StatusCode != http.StatusOK {
		fmt.Printf("%s:%d %s\n", url, resp.StatusCode, resp.Status)
		return
	}
	content, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Println(err)
		return
	}
	xkcdInfo := XkcdInfo{}
	err = json.Unmarshal(content, &xkcdInfo)
	if err != nil {
		fmt.Println(err)
		return
	}
	ch <- &xkcdInfo
}

func Search(id int, q string) (res XkcdDb) {
	if id == 0 && q == "" {
		return db
	}
	for i, info := range db {
		if i == id && i != 0 {
			res = append(res, info)
			return
		}
		if q != "" && strings.Contains(info.Title, q) {
			res = append(res, info)
		}
	}
	return res
}