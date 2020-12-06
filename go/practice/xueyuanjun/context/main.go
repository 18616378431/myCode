package main
//context

import (
	"context"
	"fmt"
	"sync/atomic"
	"time"
)

func AddNum(a *int32, b int, deferFunc func()) {
	defer func() {
		deferFunc()
	}()

	for i := 0; ; i++ {
		curNum := atomic.LoadInt32(a)
		newNum := curNum + 1
		time.Sleep(200 * time.Millisecond)
		if atomic.CompareAndSwapInt32(a, curNum, newNum) {
			fmt.Printf("number当前值: %d [%d-%d]\n", *a, b, i)
			break
		} else {
			//fmt.Printf("The CAS operation failed.[%d-%d]\n", b, i)
		}
	}
}

func main() {
	total := 10
	var num int32
	fmt.Printf("number初始值:%d\n", num)
	fmt.Println("启动子协程...")
	ctx, cancelFunc := context.WithCancel(context.Background())
	for i := 0; i < total; i++ {
		go AddNum(&num, i, func() {
			if atomic.LoadInt32(&num) == int32(total) {
				cancelFunc()
			}
		})
	}
	<-ctx.Done()
	fmt.Println("所有子协程执行完毕")

	//withValue
	var num1 int32
	ctx1, cancelFunc1 := context.WithTimeout(context.Background(),10 * time.Second)
	valueCtx := context.WithValue(ctx1, "key", "value")
	defer cancelFunc1()
	for i := 0; i < total; i++ {
		go AddNum(&num1, i, func() {
			if atomic.LoadInt32(&num1) == int32(total) {
				fmt.Println("key:", valueCtx.Value("key"))
				cancelFunc1()
			}
		})
	}
	<- ctx1.Done()
}
