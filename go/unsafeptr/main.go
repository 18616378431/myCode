package main

import (
	"fmt"
	"unsafe"
)

func main() {
	var x struct{
		a bool
		b int16
		c []int
	}

	//pb := &x.b
	pb := (*int16)(unsafe.Pointer(
		uintptr(unsafe.Pointer(&x)) + unsafe.Offsetof(x.b)))
	*pb = 42
	fmt.Println(x.b)

	//移动垃圾回收器,原变量可能已经移动,临时指针值无效
	tmp := uintptr(unsafe.Pointer(&x)) + unsafe.Offsetof(x.b)
	pb1 := (*int16)(unsafe.Pointer(tmp))
	*pb1 = 42

	fmt.Println(*pb1)

	//变量回收,没有指针指向T,语句结束后回收内存
	//pT存储变量的旧地址
	//pT := uintptr(unsafe.Pointer(new(int16)))
	//*pT = 100
}
