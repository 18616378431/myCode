package main

import (
	"fmt"
	"runtime"
	"sync"
	"time"
)

var wg sync.WaitGroup

func main() {
	//wg.Add(1)
	//go test()

	fmt.Println("NumCPU", runtime.NumCPU())
	fmt.Println("NumGoroutine", runtime.NumGoroutine())
	fmt.Println("NumCgoCall", runtime.NumCgoCall())
	fmt.Println("GOMAXPROCS", runtime.GOMAXPROCS(10))
	fmt.Println("GOMAXPROCS", runtime.GOMAXPROCS(10))

	//wg.Wait()

	start := time.Now()
	cpus := runtime.NumCPU()
	chs := make([]chan int, cpus)
	runtime.GOMAXPROCS(cpus)
	for i := 0; i < len(chs); i++ {
		chs[i] = make(chan int, 1)
		go sum(i, chs[i])
	}

	fmt.Println("NumGoroutine", runtime.NumGoroutine())

	sum := 0
	for _, ch := range chs {
		res := <- ch
		sum += res
	}

	fmt.Printf("最终将结果 : %d, 耗时 : %f\n", sum, time.Since(start).Seconds())
}

func test() {
	fmt.Println("test func")
	wg.Done()
}

func sum(seq int, ch chan <- int) {
	defer close(ch)
	sum := 0
	for i := 1; i <= 10000000; i++ {
		sum += i
	}
	ch <- sum
	fmt.Printf("子协程[%d]运算结果 : %d\n", seq, sum)
}
