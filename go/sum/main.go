package main

import "fmt"

func main() {
	fmt.Println(sum())
	fmt.Println(sum(3))
	fmt.Println(sum(1, 2, 3, 4))

	var vals = []int{1, 2, 3, 4}
	fmt.Println(sum(vals...))

	fmt.Printf("%T\n", sum)
	fmt.Printf("%T\n", f)
}

func sum(vals... int) int {
	total := 0
	for _, val := range vals {
		total += val
	}
	return total
}

func f(a []int) {

}
