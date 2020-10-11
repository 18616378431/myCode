package main

import (
	"fmt"
	"time"
)

func main() {

	go func() {
		//defer func() {
		//	if err := recover(); err != nil {
		//		fmt.Println(err)
		//	}
		//}()

		//子goroutine panic会导致整个程序崩溃退出

		panic("goroutine panic!Main goroutine is running?")
	}()

	for i := 0; i < 10; i++ {
		time.Sleep(1 * time.Second)
		fmt.Println("line:", i)
	}
}
