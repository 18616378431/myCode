package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(same("123", "122"))
	fmt.Println(same("123", "3321"))
	fmt.Println(same("123", "321"))
	fmt.Println(same("132", "321"))
}

func same(s1, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	for _, v := range s1 {
		if strings.Count(s1, string(v)) != strings.Count(s2, string(v)) {
			return false
		}
	}
	return true
}
