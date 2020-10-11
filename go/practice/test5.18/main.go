//下载网络文件并返回本地文件名和字节数
package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
	"path"
)

func main() {
	fname, n, err := fetch("https://www.csdn.net")
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	fmt.Printf("filename : %s,bytes : %d\n", fname, n)
}

func fetch(url string) (filename string, n int64, err error) {
	resp, err := http.Get(url)
	if err != nil {
		return "", 0, err
	}
	defer resp.Body.Close()
	local := path.Base(resp.Request.URL.Path)
	if local == "/" || local == "." {
		local = "index.html"
	}
	f, err := os.Create(local)
	if err != nil {
		return "", 0, err
	}
	n, err = io.Copy(f, resp.Body)
	if closeErr := f.Close(); err == nil {
		err = closeErr
	}
	return local, n, nil
}
