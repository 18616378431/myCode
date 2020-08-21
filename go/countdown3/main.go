package main

import (
	"fmt"
	"os"
	"time"
)

func main() {
	fmt.Println("commencing countdown.Press return to abort.")
	abort := make(chan struct{})
	go func() {
		os.Stdin.Read(make([]byte, 1))
		abort <- struct{}{}
	}()
	tick := time.Tick(1 * time.Second)
	for countdown := 10; countdown > 0; countdown-- {
		fmt.Println(countdown)
		select {
		case <- tick:
			//nothing
			fmt.Println("Tick")
		case <- abort:
			fmt.Println("Launch aborted!")
			return
		}
	}
	//launch()
}
