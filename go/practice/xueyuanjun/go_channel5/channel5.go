package main

import (
	"fmt"
	"time"
)
//如果我们试图向一个已经关闭的通道发送数据或关闭已经关闭的通道，也会引发 panic
func main() {
	ch := make(chan int, 1)
	timeout := make(chan bool, 1)

	go func() {
		time.Sleep(1e9)
		timeout <- true
	}()

	select {
	case <- ch:
		fmt.Println("接收到ch通道数据")
	case <- timeout:
		fmt.Println("超时1秒,程序退出")
	}
}
