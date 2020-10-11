//替换子串
package main

import "fmt"

func main() {
	foo := "foo"
	fmt.Println(expand(foo, test))
}

func expand(s string, f func(string)string) string {
	return f(s)
}

func test(a string) string {
	return a + ":xxx"
}
