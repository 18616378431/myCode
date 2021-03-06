package main

import (
	"fmt"
	"reflect"
	"strconv"
	"strings"
)

type Movie struct {
	Title, Subtitle string
	Year int
	Color bool
	Actors map[string]string
	Oscars []string
	Sequel *string
}

var maxDepth = 10

func main() {
	strangelove := Movie{
		Title : "Dr.StrangeLove",
		Subtitle : "How I",
		Year : 1964,
		Color : false,
		Actors : map[string]string{
			"Dr.StrangeLove" : "Peter Seller",
			"Grp.Capt.Lionel Mandrake" : "Peter Sellers",
		},
		Oscars : []string{
			"Best Actors",
			"Best Adapted",
			"Best Pictures",
		},
	}

	Display("strangelove", strangelove)

	//Display("os.Stderr", os.Stderr)
	//
	//Display("rV", reflect.ValueOf(os.Stderr))
	//
	//var i interface{} = 3
	//Display("i", i)
	//
	//Display("&i", &i)

	//array
	Display("ArrayKey", map[[3]int]string{
		{1, 2, 3} : "123",
		{4, 5, 6} : "456",
		{7, 8, 9} : "789",
	})

	//struct
	Display("StructKey", map[struct{
		name string
		age int
	}]string {
		{"line" ,22} : "line22",
		{"alice", 100} : "alice100",
	})

	//Node reference
	type Node struct {
		value int
		next *Node
	}

	head := &Node{0, nil}
	temp := head
	for i := 1; i < 20; i++ {
		temp.next = &Node{i, nil}
		temp = temp.next
	}

	Display("Linked-Node", head)

}

func formatAtom(v reflect.Value) string {
	switch v.Kind() {
	case reflect.Invalid:
		return "Invalid"
	case reflect.Int, reflect.Int8, reflect.Int16, reflect.Int32, reflect.Int64:
		return strconv.FormatInt(v.Int(), 10)
	case reflect.Uint, reflect.Uint8, reflect.Uint16, reflect.Uint32, reflect.Uint64, reflect.Uintptr:
		return strconv.FormatUint(v.Uint(), 10)
		//omit float
	case reflect.Bool:
		return strconv.FormatBool(v.Bool())
	case reflect.String:
		return strconv.Quote(v.String())
	case reflect.Chan, reflect.Func, reflect.Ptr, reflect.Slice, reflect.Map://reference
		return v.Type().String() + " 0x" + strconv.FormatUint(uint64(v.Pointer()), 16)
	default://reflect.Array reflect.Struct reflect.Interface
		return v.Type().String() + " value"
	}
}

func Display(name string, x interface{}) {
	fmt.Printf("Display %s (%T):\n", name, x)
	display(name, reflect.ValueOf(x), 0)
}

func display(path string, v reflect.Value, depth int) {
	if depth > maxDepth {
		fmt.Printf("%s is too deep\n", path)
		fmt.Printf("%s = %s\n", path, formatAtom(v))
		return
	}
	switch v.Kind() {
	case reflect.Invalid:
		fmt.Printf("%s = invalid\n", path)
	case reflect.Slice, reflect.Array:
		for i := 0; i < v.Len(); i++ {
			display(fmt.Sprintf("%s[%d]", path, i), v.Index(i), depth)
		}
	case reflect.Struct:
		for i := 0; i < v.NumField(); i++ {
			fieldPath := fmt.Sprintf("%s.%s", path, v.Type().Field(i).Name)
			display(fieldPath, v.Field(i), depth)
		}
	case reflect.Map:
		for _, key := range v.MapKeys() {
			switch key.Kind() {
			case reflect.Array:
				//收集key
				var keys []string
				for i := 0; i < key.Len(); i++ {
					keys = append(keys, formatAtom(key.Index(i)))
				}
				//组成括号里的内容
				arrayKey := "[" + strings.Join(keys, " ") + "]"
				display(fmt.Sprintf("%s[%s]", path, arrayKey), v.MapIndex(key), depth)
			case reflect.Struct:
				var keys []string
				for i := 0; i < key.NumField(); i++ {
					keys = append(keys, formatAtom(key.Field(i)))
				}
				structKey := "{" + strings.Join(keys, " ") + "}"
				display(fmt.Sprintf("%s[%s]", path, structKey), v.MapIndex(key), depth)
			default:
				display(fmt.Sprintf("%s[%s]", path, formatAtom(key)), v.MapIndex(key), depth)
			}
		}
	case reflect.Ptr:
		if v.IsNil() {
			fmt.Printf("%s = nil\n", path)
		} else {
			display(fmt.Sprintf("(*%s)", path), v.Elem(), depth + 1)
		}
	case reflect.Interface:
		if v.IsNil() {
			fmt.Printf("%s = nil\n", path)
		} else {
			fmt.Printf("%s.type = %s\n", path, v.Elem().Type())
			display(path + ".value", v.Elem(), depth + 1)
		}
	default://基本类型,通道,函数
		fmt.Printf("%s = %s\n", path, formatAtom(v))
	}
}
