package main

import (
	"fmt"
	"time"
)

var pc [256]byte

func init() {
	for i := range pc {
		pc[i] = pc[i / 2] + byte(i & 1)
	}
}

func PopCount(x uint64) int {
	return int(
		pc[byte(x >> (0 * 8))] +
			pc[byte(x >> (1 * 8))] +
			pc[byte(x >> (2 * 8))] +
			pc[byte(x >> (3 * 8))] +
			pc[byte(x >> (4 * 8))] +
			pc[byte(x >> (5 * 8))] +
			pc[byte(x >> (6 * 8))] +
			pc[byte(x >> (7 * 8))])
}

//for 2.3
func PopCount1(x uint64) int {
	var t int
	for i := 0; i < 8; i++ {
		t += int(pc[byte(x >> uint(i * 8))])
	}
	return t
}

//2.4
func PopCount2(x uint64) int {
	var total int
	for i := 0; i < 64; i++ {
		if (x >> uint(i)) & 1 == 1 {
			total++
		}
	}
	return total
}

//2.5
func PopCount3(x uint64) int {
	c := 0
	for {
		if x == 0 {
			break
		}
		x = x & (x - 1)
		c++
	}
	return c
}



func main() {
	s1 := time.Now()
	for i := 0; i < 100000; i++ {
		PopCount(15)
	}
	fmt.Printf("exp elapsed time : %f\n", time.Since(s1).Seconds())

	s2 := time.Now()
	for i := 0; i < 100000; i++ {
		PopCount1(15)
	}
	fmt.Printf("for elasped time : %f\n", time.Since(s2).Seconds())

	s3 := time.Now()
	for i := 0; i < 100000; i++ {
		PopCount2(15)
	}
	fmt.Printf("bit elasped time : %f\n", time.Since(s3).Seconds())

	s4 := time.Now()
	for i := 0; i < 100000; i++ {
		PopCount3(15)
	}
	fmt.Printf("&&& elasped time : %f\n", time.Since(s4).Seconds())

	fmt.Println(PopCount3(17))
}
