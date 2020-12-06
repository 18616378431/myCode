package main

import "fmt"

func main() {
	fmt.Println(Fibnacci(5))
	fmt.Println(MemFibnacci(5))
}

func Fibnacci(n int) int {
	if n == 1 {
		return 0
	}

	if n == 2 {
		return 1
	}

	return Fibnacci(n - 1) + Fibnacci(n - 2)
}

/**
虽然序号只相差了10倍，但是最终体现在执行时间上，却是不止十倍百倍的巨大差别，究其原因，
一方面是因为递归函数调用产生的额外开销，另一方面是因为目前这种实现存在着重复计算，
比如我在计算 fibonacci(50) 时，会转化为计算 fibonacci(49) 与 fibonacci(48) 之和，
然后我在计算 fibonacci(49) 时，又会转化为调用 fibonacci(48) 与 fibonacci(47) 之和，
这样一来 fibonacci(48) 就会两次重复计算，这一重复计算就是一次新的递归（从序号48递归到序号1），
依次类推，大量的重复递归计算堆积，最终导致程序执行缓慢，我们可以对这个环节进行优化，
通过缓存中间计算结果来避免重复计算，从而提升程序性能
 */
const MAX = 50
var fibs [MAX]int//内存缓存已计算结果

func MemFibnacci(n int) int {
	if n == 1 {
		return 0
	}

	if n == 2 {
		return 1
	}

	index := n - 1
	if fibs[index] != 0 {
		return fibs[index]
	}
	num := MemFibnacci(n - 1) + MemFibnacci(n - 2)
	fibs[index] = num
	return num
}