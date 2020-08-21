package main

import "fmt"

type tree struct {
	value int
	left, right *tree
}

//就地排序
func sort(values []int) []int {
	var root *tree

	for _, v := range values {
		root = add(root, v)
	}

	return appendValues(values[:0], root)
}

//将元素按顺序添加到values里面,并返回结果slice
func appendValues(values []int, t *tree) []int {
	if t != nil {
		values = appendValues(values, t.left)
		values = append(values, t.value)
		values = appendValues(values, t.right)
	}

	return values
}

//将值插入到有序二叉树中
func add(t *tree, value int) *tree {
	if t == nil {
		t = new(tree)
		t.value = value
		return t
	}

	if value < t.value {
		t.left = add(t.left, value)
	} else {
		t.right = add(t.right, value)
	}

	return t
}

func main() {
	var a = [...]int{3, 1, 2, 5, 4}
	fmt.Println(sort(a[:]))
}
