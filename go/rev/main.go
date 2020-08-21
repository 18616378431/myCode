package main

import "fmt"

func main() {
	a := [...]int{0, 1, 2, 3, 4, 5}
	reverse(a[:])
	fmt.Println(a)

	s := [...]int{0, 1, 2, 3, 4, 5}
	//向左移动两个元素
	reverse(s[:2])
	fmt.Println(s)

	reverse(s[2:])
	fmt.Println(s)

	reverse(s[:])
	fmt.Println(s)
}

//反转slice
func reverse(s []int) {
	for i, j := 0, len(s) - 1; i < j; i, j = i + 1, j - 1 {
		s[i], s[j] = s[j], s[i]
	}
}
