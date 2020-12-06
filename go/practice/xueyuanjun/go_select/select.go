package main

import (
	"fmt"
	"math/rand"
)

func test() {
	chs := [3]chan int {
		make(chan int, 3),
		make(chan int, 3),
		make(chan int, 3),
	}

	index1 := rand.Intn(3)
	fmt.Printf("所及索引/数值: %d\n", index1)
	chs[index1] <- rand.Int()

	index2 := rand.Intn(3)
	fmt.Printf("所及索引/数值: %d\n", index2)
	chs[index2] <- rand.Int()

	index3 := rand.Intn(3)
	fmt.Printf("所及索引/数值: %d\n", index3)
	chs[index3] <- rand.Int()

	for i := 0; i < 3; i++ {
		select {
		case num, ok := <- chs[0]:
			if !ok {
				break
			}
			fmt.Println("第一个条件分支被选中:chs[0] => ", num)
		case num, ok := <- chs[1]:
			if !ok {
				break
			}
			fmt.Println("第二个条件分支被选中:chs[1] => ", num)
		case num, ok := <- chs[2]:
			if !ok {
				break
			}
			fmt.Println("第三个条件分支被选中:chs[2] => ", num)
		default:
			fmt.Println("没有分支被选中")
		}
	}
}

func main() {
	chs := [3]chan int {
		make(chan int, 1),
		make(chan int, 1),
		make(chan int, 1),
	}

	index := rand.Intn(3)//0-2
	fmt.Printf("随机索引/数值: %d\n", index)
	chs[index] <- index

	select {
	case <- chs[0]:
		fmt.Println("第一个条件分支被选中")
	case <- chs[1]:
		fmt.Println("第二个条件分支被选中")
	case num := <- chs[2]:
		fmt.Println("第三个条件分支被选中", num)
	default:
		fmt.Println("没有条件分支被选中")
	}

	fmt.Println("----")

	test()
}
