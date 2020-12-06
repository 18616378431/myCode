package main

import (
	"context"
	"fmt"
	"sync"
	"sync/atomic"
	"time"
)

func add_num(a, b int, deferFunc func()) {
	defer func() {
		deferFunc()
	}()
	c := a + b
	fmt.Printf("%d + %d = %d\n", a, b, c)
}

func test() {
	total := 10
	step := 2
	fmt.Println("启动子协程...")
	var wg sync.WaitGroup
	for i := 0; i < total; i += step {
		wg.Add(step)
		for j := 0; j < step; j++ {
			go add_num(i + j, 1, wg.Done)
		}
		wg.Wait()
	}
	fmt.Println("所有子协程执行完毕.")
}

func AddNum(a *int32, b int, deferFunc func()) {
	defer func() {
		deferFunc()
	}()
	for i := 0; ; i++ {
		curNum := atomic.LoadInt32(a)
		newNum := curNum + 1
		time.Sleep(time.Millisecond * 200)
		if atomic.CompareAndSwapInt32(a, curNum, newNum) {
			fmt.Printf("number当前值:%d [%d-%d]\n", *a, b, i)
			break
		} else {
			//fmt.Printf("CAS Failed:[%d-%d]\n", b, i)
			//os.Exit(-1)
		}
	}
}

func main() {
	//total := 10
	//var num int32
	//fmt.Printf("number初始值:%d\n", num)
	//fmt.Println("启动子协程...")
	//ctx, cancelFunc := context.WithCancel(context.Background())
	//for i := 0; i < total; i++ {
	//	go AddNum(&num, i, func() {
	//		if atomic.LoadInt32(&num) == int32(total) {
	//			cancelFunc()
	//		}
	//	})
	//}
	//<- ctx.Done()
	//fmt.Println("所有子协程执行完毕")

	total := 10
	var num int32
	fmt.Printf("number初始值:%d\n", num)
	fmt.Println("启动子协程...")
	ctx, cancelFunc := context.WithTimeout(context.Background(), 10 * time.Second)
	valueCtx := context.WithValue(ctx, "key", "value")
	defer cancelFunc()
	for i := 0; i < total; i++ {
		go AddNum(&num, i, func() {
			if atomic.LoadInt32(&num) == int32(total) {
				fmt.Println("key:", valueCtx.Value("key"))
				cancelFunc()
			}
		})
	}
	<- ctx.Done()
	fmt.Println("所有子协程执行完毕")
}
