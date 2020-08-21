package main

import "fmt"

func main() {
	var a = [...]int{0, 1, 2, 3, 4, 5}
	fmt.Println(a)
	fmt.Println(appendInt(a[:], 6))

	var x, y []int
	for i := 0; i < 10; i++ {
		y = appendInt(x, i)
		fmt.Printf("%d cap = %d\t%v\n", i, cap(y), y)
		x = y
	}

	var m []int
	m = append(m, 1)
	m = append(m, 2, 3)
	m = append(m, 4, 5, 6)
	m = append(m, m...)
	fmt.Println(m)

	m = appendInt1(m, 0, 0, 0, 0, 0)
	fmt.Println(m)
}

func appendInt(x []int, y int) []int {
	var z []int

	zlen := len(x) + 1

	//fmt.Printf("zlen:%d,cap(x):%d,len(x):%d\n", zlen, cap(x), len(x))

	if zlen <= cap(x) {
		//slice仍有增长空间,扩展slice
		z = x[:zlen]
	} else {
		//slice已无空间,分配新的底层数组
		//达到线性分摊复杂性,容量空充一倍
		zcap := zlen

		if zcap < 2 * len(x) {
			zcap = 2 * len(x)
		}
		z = make([]int, zlen, zcap)
		copy(z, x)
	}
	z[len(x)] = y

	return z
}

func appendInt1(x []int, y ...int) []int {
	var z []int

	zlen := len(x) + len(y)

	//fmt.Printf("zlen:%d,cap(x):%d,len(x):%d\n", zlen, cap(x), len(x))

	if zlen <= cap(x) {
		//slice仍有增长空间,扩展slice
		copy(z[len(x):], y)
	} else {
		//slice已无空间,分配新的底层数组
		//达到线性分摊复杂性,容量空充一倍
		zcap := zlen

		if zcap < 2 * len(x) {
			zcap = 2 * len(x)
		} else {
			zcap = 2 * (len(x) + len(y))
		}
		z = make([]int, zlen, zcap)
		copy(z, x)
		copy(z[len(x):], y)
	}

	return z
}
