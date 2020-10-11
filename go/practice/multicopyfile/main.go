//大文件分chunk多协程拷贝
package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strings"
	"sync"
)

const mb = 1024 * 1024
const gb = 1024 * mb

func main() {
	//WaitGroup
	wg := sync.WaitGroup{}

	//send word
	channel := make(chan string)

	//dict
	dict := make(map[string]int64)

	//done to signal the main thread everything is done
	done := make(chan bool, 1)

	//file
	var fileName string = "test.txt"

	//file size to split goroutine
	file, err := os.Open(fileName)

	if err != nil {
		panic(err)
	}

	defer file.Close()

	fi, err := file.Stat()

	if err != nil {
		panic(err)
	}

	fileSize := fi.Size()

	//read all incoming words from channel and add to dict
	go func() {
		for s := range channel {

			//fmt.Println(s)
			dict[s]++
		}
		done <- true
	}()

	var current int64

	//var limit int64 = 500 * mb
	var limit int64 = 20

	//compute goroutine count
	var c = int32(math.Ceil(float64(fileSize) / float64(limit)))

	for i := 0; i < int(c); i++ {
		wg.Add(1)

		//read(current, limit, "test.txt", channel)

		go func(i int, current, limit int64) {
			read(current, limit, "test.txt", channel)
			fmt.Printf("%d thread has been completed\n", i)
			wg.Done()
		}(i, current, limit)

		//fmt.Println(current)
		current += limit + 1
	}
	//wait for all goroutine to complete
	wg.Wait()
	close(channel)

	//wait dict process all words
	<-done
	close(done)

	fmt.Printf("%v\n", dict)
}

func read(offset int64, limit int64, fileName string, channel chan string) {
	file, err := os.Open(fileName)
	defer file.Close()

	if err != nil {
		panic(err)
	}

	//Move the pointer of the file to the start of designated chunk
	file.Seek(offset, 0)
	reader := bufio.NewReader(file)

	//ensure the start position is the begin of a word
	if offset != 0 {
		_, err = reader.ReadBytes(' ')
		if err == io.EOF {
			fmt.Println("EOF")
			return
		}
		if err != nil {
			panic(err)
		}
	}
	var cummulativeSize int64
	for {
		//break if read size has exceed the chunk size
		if cummulativeSize > limit {
			break
		}
		b, err := reader.ReadBytes(' ')

		if err == io.EOF {
			break
		}
		if err != nil {
			panic(err)
		}
		cummulativeSize += int64(len(b))
		s := strings.TrimSpace(string(b))

		fmt.Println(s, offset, limit)

		if s != "" {
			//send the read word in the channel to enter into dict
			channel <- s
		}
	}
}
