package main

import (
	"fmt"
	"os"
	"reflect"
	"strconv"
)

type Movie struct {
	Title, Subtitle string
	Year int
	Color bool
	Actors map[string]string
	Oscars []string
	Sequel *string
}

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

	Display("os.Stderr", os.Stderr)

	Display("rV", reflect.ValueOf(os.Stderr))

	var i interface{} = 3
	Display("i", i)

	Display("&i", &i)
}

func formatAtom(v reflect.Value) string {
	switch v.Kind() {
	case reflect.Invalid:
		return "Invalid"
	case reflect.Int, reflect.Int8, reflect.Int16, reflect.Int32, reflect.Int64:
		return strconv.FormatInt(v.Int(), 10)
	case reflect.Uint, reflect.Uint8, reflect.Uint16, reflect.Uint32, reflect.Uint64:
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
	display(name, reflect.ValueOf(x))
}

func display(path string, v reflect.Value) {
	switch v.Kind() {
	case reflect.Invalid:
		fmt.Printf("%s = invalid\n", path)
	case reflect.Slice, reflect.Array:
		for i := 0; i < v.Len(); i++ {
			display(fmt.Sprintf("%s[%d]", path, i), v.Index(i))
		}
	case reflect.Struct:
		for i := 0; i < v.NumField(); i++ {
			fieldPath := fmt.Sprintf("%s.%s", path, v.Type().Field(i).Name)
			display(fieldPath, v.Field(i))
		}
	case reflect.Map:
		for _, key := range v.MapKeys() {
			display(fmt.Sprintf("%s[%s]", path, formatAtom(key)), v.MapIndex(key))
		}
	case reflect.Ptr:
		if v.IsNil() {
			fmt.Printf("%s = nil\n", path)
		} else {
			display(fmt.Sprintf("(*%s)", path), v.Elem())
		}
	case reflect.Interface:
		if v.IsNil() {
			fmt.Printf("%s = nil\n", path)
		} else {
			fmt.Printf("%s.type = %s\n", path, v.Elem().Type())
			display(path + ".value", v.Elem())
		}
	default://基本类型,通道,函数
		fmt.Printf("%s = %s\n", path, formatAtom(v))
	}
}
