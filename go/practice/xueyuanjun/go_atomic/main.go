package main

import (
	"fmt"
	"sync/atomic"
)

func main() {
	//add
	var i int32 = 1
	atomic.AddInt32(&i, 1)
	fmt.Println("i = i + 1 = ", i)
	atomic.AddInt32(&i, -1)
	fmt.Println("i = i - 1 = ", i)

	//cas
	var a int32 = 1
	var b int32 = 2
	var c int32 = 2
	atomic.CompareAndSwapInt32(&a, a, b)
	atomic.CompareAndSwapInt32(&b, b, c)
	fmt.Println("a, b, c:", a, b, c)

	//load
	//这里的「原子性」指的是当读取该指针指向的值时，CPU 不会执行任何其它针对此值的读写操作
	var x int32 = 100
	y := atomic.LoadInt32(&x)
	fmt.Println("x, y:", x, y)

	//store load的逆向操作
	var x1 int32 = 100
	var y1 int32
	atomic.StoreInt32(&y1, atomic.LoadInt32(&x1))
	fmt.Println("x, y:", x, y)

	//swap
	var j int32 = 1
	var k int32 = 2
	j_old := atomic.SwapInt32(&j, k)
	fmt.Println("old, new:", j_old, j)

	//value
	//首先，存储值不能是 nil；其次，我们向原子类型存储的第一个值，决定了它今后能且只能存储该类型的值。如果违背这两条，编译时会抛出 panic。
	var v atomic.Value
	v.Store(100)
	fmt.Println("v:", v.Load())

}
