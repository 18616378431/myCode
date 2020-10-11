//变长函数
package main

import (
	"errors"
	"fmt"
)

func main() {
	var input = []int{0, 1, 2, 3, 4}
	m, _ := max(input...)
	fmt.Printf("max : %d\n", m)

	m1, _ := min(input...)
	fmt.Printf("min : %d\n", m1)

	first := input[0]
	left := input[1:]
	fmt.Printf("mustMax : %d\n", mustMax(first, left...))
	fmt.Printf("mustMin : %d\n", mustMin(first, left...))
}

func max(vals ...int) (int, error) {
	if len(vals) == 0 {
		return 0, errors.New("must have at least one argument")
	}
	max := vals[0]
	for _, v := range vals {
		if v > max {
			max = v
		}
	}
	return max, nil
}

func min(vals ...int) (int, error) {
	if len(vals) == 0 {
		return 0, errors.New("must have at least one argument")
	}
	min := vals[0]
	for _, v := range vals {
		if v < min {
			min = v
		}
	}
	return min, nil
}

func mustMax(first int, vals ...int) int {
	max := first
	for _, v := range vals {
		if v > max {
			max = v
		}
	}
	return max
}

func mustMin(first int, vals ...int) int {
	min := first
	for _, v := range vals {
		if v < min {
			min = v
		}
	}
	return min
}
