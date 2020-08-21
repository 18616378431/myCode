package main

import "fmt"

func main() {
	naturals := make(chan int)
	squares := make(chan int)

	//counter
	go func() {
		for x := 0; ; x++ {
			naturals <- x
		}
	}()

	//squares
	go func() {
		for {
			x, ok := <-naturals
			if !ok {
				break
			}
			squares <- x * x
		}
		close(squares)
	}()

	//printer
	for {
		fmt.Println(<-squares)
	}
}
