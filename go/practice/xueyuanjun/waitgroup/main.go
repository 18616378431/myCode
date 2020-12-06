package main

import (
	"fmt"
	"sync"
	"time"
)

var wg sync.WaitGroup
var once sync.Once

func main() {
	for i := 0; i < 10; i++ {
		wg.Add(1)
		go Add(i, 1)
	}
	wg.Wait()

	//Once
	DoSomething()
	DoSomething()
	DoSomething()
	time.Sleep(1 * time.Second)

	//分批启动子协程
	step := 2
	for i := 0; i < 10; i++ {
		wg.Add(step)
		for j := 0; j < step; j++ {
			go Add(1, i + j)
		}
		wg.Wait()
		fmt.Println("----")
	}
	fmt.Println("所有子协程执行完毕")
}

func Add(a, b int) {
	defer wg.Done()
	c := a + b
	fmt.Printf("%d + %d = %d\n", a, b, c)
}

func DoSomething() {
	fmt.Printf("start\n")
	once.Do(func() {
		fmt.Println("Do Something")
	})
	fmt.Printf("Finish\n")
}
