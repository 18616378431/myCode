package main

import (
	"fmt"
)

func main() {
	fmt.Println("commencing countdown.")
	//tick := time.Tick(1 * time.Second)
	//abort := make(chan struct{})
	//go func() {
	//	os.Stdin.Read(make([]byte, 1))
	//	abort <- struct{}{}
	//}()
	//for countdown := 10; countdown > 0; countdown-- {
	//	fmt.Println(countdown)
	//	<- tick
	//}
	//launch()

	ch := make(chan int, 1)
	for i := 0; i < 10; i++ {
		select {
		case x := <- ch:
			fmt.Println(x)
		case ch <- i:
		}
	}
}
