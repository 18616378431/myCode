package main

import (
	"bytes"
	"fmt"
	"go/scanner"
	"reflect"
	"strconv"
)

type Movie struct {
	Title, Subtitle string
	Year int
	//Color bool
	Actors map[string]string
	Oscars []string
	Sequel *string
}

func main() {
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
	}
	r, err := Marshal(strangelove)
	fmt.Printf("%s,%s\n", r, err)
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
	default://float, complex, bool, chan, func, interface
		return fmt.Errorf("unsupported type : %s", v.Type())
	}
	return nil
}

//Decode
type lexer struct {
	scan scanner.Scanner
	token rune//当前标记
}

func (lex *lexer) next() {
	lex.token = lex.scan.Scan()
}

func (lex *lexer) text() string {
	return lex.scan.TokenText()
}


func (lex *lexer) consume(want rune) {
	if lex.token != want {
		panic(fmt.Sprintf("got %q,want %q", lex.text(), want))
	}
	lex.next()
}

func read(lex *lexer, v reflect.Value) {
	//nil struct field name
	if lex.text() == "nil" {
		v.Set(reflect.Zero(v.Type()))
		lex.next()
		return
	}
	
	switch lex.token {
	case scanner.String:
		s, _ := strconv.Unquote(lex.text())
		v.SetString(s)
		lex.next()
		return
	case scanner.Int:
		i, _ := strconv.Atoi(lex.text())
		v.SetInt(int64(i))
		lex.next()
		return
	case '(':
		lex.next()
		readList(lex, v)
		lex.next()//consume (
		return
	}
	panic(fmt.Sprintf("unexpected token %q", lex.text()))
}

func readList(lex *lexer, v reflect.Value) {
	switch v.Kind() {
	case reflect.Array://(item...)
		for i := 0; !endList(lex); i++ {
			read(lex, v.Index(i))
		}
	case reflect.Slice://(item...)
		for !endList(lex) {
			item := reflect.New(v.Type().Elem()).Elem()
			read(lex, item)
			v.Set(reflect.Append(v, item))
		}
	case reflect.Struct://((name value)...)
		for !endList(lex) {
			lex.consume('(')
			if lex.token != scanner.Ident {
				panic(fmt.Sprintf("got token %q, want field name", lex.text()))
			}
			name := lex.text()
			lex.next()
			read(lex, v.FieldByName(name))
			lex.consume(')')
		}
	case reflect.Map://((key value)...)
		v.Set(reflect.MakeMap(v.Type()))
		for !endList(lex) {
			lex.consume('(')
			key := reflect.New(v.Type().Key()).Elem()
			read(lex, key)
			value := reflect.New(v.Type().Elem()).Elem()
			read(lex, value)
			v.SetMapIndex(key, value)
			lex.consume(')')
		}
	default:
		panic(fmt.Sprintf("cannot decode list into %v", v.Type()))
	}
}

func endList(lex *lexer) bool {
	switch lex.token {
	case scanner.EOF:
		panic("end of file")
	case ')':
		return true
	}
	return false
}

func Unmarshal(data []byte, out interface{}) (err error) {
	lex := &lexer{scan : scanner.Scanner{Mode : scanner.GoTokens}}
	lex.scan.Init(bytes.NewReader(data))
	lex.next()//获取第一个标记
	defer func() {
		if x := recover(); x != nil {
			err = fmt.Errorf("error at %s : %v", lex.scan.Position, x)
		}
	}()
	read(lex, reflect.ValueOf(out).Elem())
	return nil
}
