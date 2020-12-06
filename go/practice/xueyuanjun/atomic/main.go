//原子操作
package main

import (
	"fmt"
	"sync/atomic"
)

func main() {
	//add
	var i int32 = 100
	atomic.AddInt32(&i, 10)
	fmt.Println(i)

	//compareandswapint32
	var a int32 = 1
	var b int32 = 2
	var c int32 = 2

	fmt.Println(atomic.CompareAndSwapInt32(&a, a, b))
	fmt.Println(a, b)

	fmt.Println(atomic.CompareAndSwapInt32(&b, b, c))
	fmt.Println(b, c)

	//load
	var x int32 = 10
	y := atomic.LoadInt32(&x)
	fmt.Println(y)

	//storeInt32
	var m int32
	atomic.StoreInt32(&m, 1000)

	fmt.Println(m)

	//swap
	var j int32 = 1
	var k int32 = 2
	old := atomic.SwapInt32(&j, k)
	fmt.Println("old, new", old, j)

	//Value interface{}
	// 首先，存储值不能是 nil；
	// 其次，我们向原子类型存储的第一个值，决定了它今后能且只能存储该类型的值。
	// 如果违背这两条，编译时会抛出 panic。
	var v atomic.Value
	v.Store(100)
	fmt.Println(v.Load())
}
