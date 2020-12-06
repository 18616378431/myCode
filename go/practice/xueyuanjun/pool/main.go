//pool
package main

import (
	"fmt"
	"sync"
)

func main() {
	//var pool = &sync.Pool{
	//	New: func() interface{} {
	//		return "Hello World!"
	//	},
	//}
	//value := "Hello, 学院君"
	//pool.Put(value)
	//fmt.Println(pool.Get())
	//fmt.Println(pool.Get())

	fmt.Println("----")
	var wg sync.WaitGroup
	var pool1 = &sync.Pool{
		New: func() interface{} {
			return "Hello World!1"
		},
	}
	wg.Add(1)
	go testPool(pool1, wg.Done)
	wg.Wait()
	fmt.Println(pool1.Get())
}

func testPool(pool *sync.Pool, deferFunc func()) {
	defer deferFunc()
	value := "Hello 学院君"
	pool.Put(value)
}