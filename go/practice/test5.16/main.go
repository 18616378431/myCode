//变长版本的strings.Join
package main

import (
	"fmt"
	"strings"
)

func main() {
	//变长规则
	//最后一个值为分隔符
	str := []string{"aaa", "bbb", "ccc", "ddd", "|"}
	fmt.Println(join(str...))
	fmt.Println(join1(str...))
}

func join(str ...string) string {
	if len(str) < 2 {
		return ""
	}
	tempStr := str[0:len(str) - 1]
	t, sep := "", ""
	for _, s := range tempStr {
		t += sep + s
		sep = str[len(str) - 1]
	}
	return t
}

func join1(strs ...string) string {
	if len(strs) < 2 {
		return ""
	}
	sep := strs[len(strs) - 1]
	last := strs[len(strs) - 2]
	tempStr := strs[:len(strs) - 2]
	b := strings.Builder{}
	for _, s := range tempStr {
		b.WriteString(s)
		b.WriteString(sep)
	}
	b.WriteString(last)
	return b.String()
}
