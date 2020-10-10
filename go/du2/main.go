package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
	"time"
)

var verbose = flag.Bool("v", false, "show verbose progress messages")

func main() {
	flag.Parse()
	roots := flag.Args()
	if len(roots) == 0 {
		roots = []string{"."}
	}
	//遍历文件树
	fileSizes := make(chan int64)
	go func() {
		for _, root := range roots {
			walkDir(root, fileSizes)
		}
		close(fileSizes)
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
			}
		}
	printDiskUsage(nfiles, nbytes)
}

//返回目录中的条目
func dirents(dir string) []os.FileInfo {
	entries, err := ioutil.ReadDir(dir)
	if err != nil {
		fmt.Fprintf(os.Stderr, "du1 : %v\n", err)
		return nil
	}
	return entries
}

//递归遍历目录,并将文件大小发送到fileSizes通道
func walkDir(dir string, fileSizes chan <- int64) {
	for _, entry := range dirents(dir) {
		if entry.IsDir() {
			subdir := filepath.Join(dir, entry.Name())
			walkDir(subdir, fileSizes)
		} else {
			fileSizes <- entry.Size()
		}
	}
}

func printDiskUsage(nfiles, nbytes int64) {
	fmt.Printf("%d files %.1fGB\n", nfiles, float64(nbytes / 1e9))
}