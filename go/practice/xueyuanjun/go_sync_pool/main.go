package main

import (
	"fmt"
	"sync"
)

func main() {
	//sync.Pool 本身是并发安全
	//var pool = &sync.Pool{
	//	New: func() interface{} {
	//		return "Hello World!"
	//	},
	//}
	//value := "Hello,XYJ"
	//pool.Put(value)
	//fmt.Println(pool.Get())
	//fmt.Println(pool.Get())

	var wg sync.WaitGroup
	wg.Add(1)
	var pool = &sync.Pool{
		New: func() interface{} {
			return "Hello,World!"
		},
	}
	go test_put(pool, wg.Done)
	wg.Wait()
	fmt.Println(pool.Get())
	fmt.Println(pool.Get())
	fmt.Println(pool.Get())
}

func test_put(pool *sync.Pool, deferFunc func()) {
	defer func() {
		deferFunc()
	}()
	value := "Hello,XYJ"
	pool.Put(value)
}
