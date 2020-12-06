package main

import (
	"fmt"
	"net/http"
	"os"
)

func main() {
	resp, err := http.Head("http://www.baidu.com")
	if err != nil {
		fmt.Fprintf(os.Stderr, "Head Request error : %s\n", err)
		os.Exit(1)
	}
	defer resp.Body.Close()
	//打印头信息
	for k, v := range resp.Header {
		fmt.Println(k, " : ", v)
	}
}
