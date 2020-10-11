package main

import (
	"bytes"
	"fmt"
	"reflect"
)

type Movie struct {
	Title, Subtitle string
	Year int
	//Color bool
	Actors map[string]string
	Oscars []string
	Sequel *string
	//f float64
	//v complex128
	//s interface{}
}

func main() {
	type w struct {
		s interface{}
	}
	//i := w{[]int{1, 2, 3}}
	strangelove := Movie{
		Title:    "Dr.StrangeLove",
		Subtitle: "How I",
		Year:     1964,
		//Color:    false,
		Actors: map[string]string{
			"Dr.StrangeLove":           "Peter Seller",
			"Grp.Capt.Lionel Mandrake": "Peter Sellers",
		},
		Oscars: []string{
			"Best Actors",
			"Best Adapted",
			"Best Pictures",
		},
		//f : 12.2,
		//v : 1 + 2i,
		//&i,
	}
	r, err := Marshal(strangelove)
	fmt.Printf("%s\n%v\n", r, err)
}

func Marshal(v interface{}) ([]byte, error) {
	var buf bytes.Buffer
	if err := encode(&buf, reflect.ValueOf(v)); err != nil {
		return nil, err
	}
	return buf.Bytes(), nil
}

func encode(buf *bytes.Buffer, v reflect.Value) error {
	switch v.Kind() {
	case reflect.Invalid:
		buf.WriteString("nil")
	case reflect.Int, reflect.Int8, reflect.Int16, reflect.Int32, reflect.Int64:
		fmt.Fprintf(buf, "%d", v.Int())
	case reflect.Uint, reflect.Uint8, reflect.Uint16, reflect.Uint32, reflect.Uint64, reflect.Uintptr:
		fmt.Fprintf(buf, "%d", v.Uint())
	case reflect.String:
		fmt.Fprintf(buf, "%q", v.String())
	case reflect.Ptr:
		return encode(buf, v.Elem())
	case reflect.Array, reflect.Slice://(value...)
		buf.WriteByte('(')
		for i := 0; i < v.Len(); i++ {
			if i > 0 {
				buf.WriteByte(' ')
			}
			if err := encode(buf, v.Index(i)); err != nil {
				return err
			}
		}
		buf.WriteByte(')')
	case reflect.Struct://(name value)
		buf.WriteByte('(')
		for i := 0; i < v.NumField(); i++ {
			if i > 0 {
				buf.WriteByte(' ')
			}
			fmt.Fprintf(buf, "(%s ", v.Type().Field(i).Name)
			if err := encode(buf, v.Field(i)); err != nil {
				return err
			}
			buf.WriteByte(')')
		}
		buf.WriteByte(')')
	case reflect.Map://((key value)...)
		buf.WriteByte('(')
		for i, key := range v.MapKeys() {
			if i > 0 {
				buf.WriteByte(' ')
			}
			buf.WriteByte('(')
			if err := encode(buf, key); err != nil {
				return err
			}
			buf.WriteByte(' ')
			if err := encode(buf, v.MapIndex(key)); err != nil {
				return err
			}
			buf.WriteByte(')')
		}
		buf.WriteByte(')')
	//float, complex, bool, interface
	//case reflect.Bool:
	//	if v.Bool() {
	//		buf.WriteByte('t')
	//	} else {
	//		buf.WriteString("nil")
	//	}
	//case reflect.Float32, reflect.Float64:
	//	fmt.Fprintf(buf, "%g", v.Float())
	//case reflect.Complex64, reflect.Complex128:
	//	c := v.Complex()
	//	fmt.Fprintf(buf, "#C(%g %g)", real(c), imag(c))
	//case reflect.Interface:
	//	if v.IsNil() {
	//		fmt.Fprintf(buf, "nil")
	//	} else {
	//		fmt.Fprintf(buf, "(%q", v.Elem().Type())
	//		encode(buf, v.Elem())
	//		buf.WriteByte(')')
	//	}
	default://chan, func
		return fmt.Errorf("unsupported type : %s", v.Type())
	}
	return nil
}
