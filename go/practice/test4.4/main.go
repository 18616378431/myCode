package main

import "fmt"

func main() {
	a := [...]int{1, 2, 3, 4, 5}
	fmt.Println(a)

	fmt.Println(rotate(a[:], 2))
}

//旋转slice
func rotate(s []int, n int) (t []int) {
	if n <= 0 || n > len(s) {
		return s
	}
	t = make([]int, len(s))
	for i, v := range s {
		t[(i + n) % len(s)] = v
	}
	return
}