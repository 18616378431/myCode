package main

import (
	"fmt"
	"sort"
)

func main() {
	slice1 := []int{1, 2, 3, 4, 5}
	slice2 := []int{5, 4, 3}

	//copy(slice2, slice1)
	//fmt.Println(slice2)

	copy(slice1, slice2)
	fmt.Println(slice1)

	var testMap map[string]int
	testMap = map[string]int{
		"one" : 1,
		"two" : 2,
		"three" : 3,
	}
	k := "two"
	v, ok := testMap[k]
	if ok {
		fmt.Printf("The element of key %q : %d\n", k, v)
	} else {
		fmt.Printf("Not Found\n")
	}

	var testMap1 = make(map[string]int, 100)
	testMap1["one"] = 1
	testMap1["two"] = 2
	testMap1["three"] = 3
	testMap1["four"] = 4

	k1 := "three"
	v1, ok1 := testMap[k1]
	if ok1 {
		fmt.Printf("The element of key %q : %d\n", k1, v1)
	} else {
		fmt.Printf("Not Found\n")
	}

	fmt.Println(testMap1)
	delete(testMap1, "four")
	fmt.Println(testMap1)

	var testMap2 map[string]int
	delete(testMap2, "ttt")

	fmt.Println(testMap2)

	//遍历map
	for key, value := range testMap1 {
		fmt.Println(key, "=", value)
	}

	//仅获取值
	for _, value := range testMap1 {
		fmt.Println(value)
	}

	//仅获取key
	for key := range testMap1 {
		fmt.Println(key)
	}

	fmt.Println("键值对调")
	invMap := make(map[int]string, 3)
	for k, v := range testMap1 {
		invMap[v] = k
	}
	for k, v := range invMap {
		fmt.Println(k, v)
	}

	fmt.Println("字典排序")
	//先对键进行排序,再遍历键输出
	keys := make([]string, 0)
	for k, _ := range testMap1 {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	fmt.Println("Sorted map by key")
	for _, k := range keys {
		fmt.Println(k, testMap1[k])
	}

	fmt.Println("对字典进行值升序排序")
	values := make([]int, 0)
	for _, v := range testMap1 {
		values = append(values, v)
	}
	sort.Ints(values)
	fmt.Println("Sorted map by value")
	for _, v := range values {
		fmt.Println(invMap[v], v)
	}

	fmt.Println("指针")
	a := 100
	ptr := &a
	fmt.Println(ptr)
	fmt.Println(*ptr)

	var ptr1 *int
	fmt.Println(ptr1)

	fmt.Println("指针传值")
	a1 := 1
	b1 := 2
	swap(a1, b1)
	fmt.Println(a1, b1)

	swap1(&a1, &b1)
	fmt.Println(a1, b1)
}

func swap(a, b int) {
	a, b = b, a
	fmt.Println(a, b)
}

func swap1(a, b *int) {
	*a, *b = *b, *a
	fmt.Println(*a, *b)
}