package main

import "fmt"

func main() {
	a := [...]int{0, 1, 2, 3, 4}
	fmt.Println("before reverse",a)

	reverse(&a)
	fmt.Println("after reverse", a)
}

func reverse(arr *[5]int) {
	length := len(*arr)
	for i, j := 0, length - 1; i < j; i, j = i + 1, j - 1 {
		(*arr)[i], (*arr)[j] = (*arr)[j], (*arr)[i]
	}
}