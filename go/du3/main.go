package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
	"sync"
	"time"
)

var verbose = flag.Bool("v", false, "show verbose progress messages")

var sema = make(chan struct{}, 20)

var done = make(chan struct{})

func main() {
	flag.Parse()
	roots := flag.Args()
	if len(roots) == 0 {
		roots = []string{"."}
	}
	//遍历文件树
	fileSizes := make(chan int64)
	var n sync.WaitGroup
	for _, root := range roots {
		n.Add(1)
		go walkDir(root, &n, fileSizes)
	}
	go func() {
		n.Wait()
		close(fileSizes)
	}()

	//终止程序
	go func() {
		os.Stdin.Read(make([]byte, 1))
		close(done)
	}()

	//定期输出结果
	var tick <- chan time.Time
	if *verbose {
		tick = time.Tick(500 * time.Millisecond)
	}
	var nfiles, nbytes int64
loop:
	for {
		select {
		case size, ok := <- fileSizes:
			if !ok {
				break loop
			}
			nfiles++
			nbytes += size
		case <- tick:
			printDiskUsage(nfiles, nbytes)
		case <- done:
			//耗尽fileSizes以允许所有goroutine结束
			for range fileSizes {

			}
			return
		}
	}
	printDiskUsage(nfiles, nbytes)
}

//返回目录中的条目
func dirents(dir string) []os.FileInfo {
	select {
	case sema <- struct{}{}://获取令牌
	case <- done:
		return nil
	}
	defer func() {
		<- sema//释放令牌
	}()
	entries, err := ioutil.ReadDir(dir)
	if err != nil {
		fmt.Fprintf(os.Stderr, "du1 : %v\n", err)
		return nil
	}
	return entries
}

//递归遍历目录,并将文件大小发送到fileSizes通道
func walkDir(dir string,n *sync.WaitGroup, fileSizes chan <- int64) {
	defer n.Done()
	if cancelled() {
		return
	}
	for _, entry := range dirents(dir) {
		if entry.IsDir() {
			n.Add(1)
			subdir := filepath.Join(dir, entry.Name())
			go walkDir(subdir, n, fileSizes)
		} else {
			fileSizes <- entry.Size()
		}
	}
}

func printDiskUsage(nfiles, nbytes int64) {
	fmt.Printf("%d files %.1fGB\n", nfiles, float64(nbytes / 1e9))
}

func cancelled() bool {
	select {
	case <- done:
		return true
	default:
		return false
	}
}