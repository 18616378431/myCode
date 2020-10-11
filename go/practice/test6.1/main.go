package main

import (
	"bytes"
	"fmt"
)

type IntSet struct {
	words []uint64
}

//是否存在非负数
func (s *IntSet) Has(x int) bool {
	word, bit := x / 64, uint(x % 64)
	return word < len(s.words) && s.words[word] & (1 << bit) != 0
}

//添加非负数到集合
func (s *IntSet) Add(x int) {
	word, bit := x / 64, uint(x % 64)
	for word >= len(s.words) {
		s.words = append(s.words, 0)
	}
	s.words[word] |= 1 << bit
}

//求并集
func (s *IntSet) UnionWith(t * IntSet) {
	for i, tword := range t.words {
		if i < len(s.words) {
			s.words[i] |= tword
		} else {
			s.words = append(s.words, tword)
		}
	}
}

//转换为字符串
func (s *IntSet) String() string {
	var buf bytes.Buffer
	buf.WriteByte('{')
	for i, word := range s.words {
		if word == 0 {
			continue
		}
		for j := 0; j < 64; j++ {
			if word & (1 << uint(j)) != 0 {
				if buf.Len() > len("{") {
					buf.WriteByte(' ')
				}
				fmt.Fprintf(&buf, "%d", 64 * i + j)
			}
		}
	}
	buf.WriteByte('}')
	return buf.String()
}

func (s *IntSet) Len() int {
	count := 0
	for _, word := range s.words {
		for mask := uint(0); mask < 64; mask++ {
			if word & (1 << mask) != 0 {
				count++
			}
		}
	}
	return count
}

func (s *IntSet) Remove(x int) {
	word, bit := x / 64, uint(x % 64)
	if word > len(s.words) {
		return
	}
	s.words[word] &^= 1 << bit
}

func (s *IntSet) Clear() {
	s.words = nil
}

//func (s *IntSet) Copy() *IntSet {
//	n := &IntSet{}
//	copy(n.words, s.words)
//	return n
//}

func (s *IntSet) Copy() *IntSet {
	n := &IntSet{}
	fmt.Println(s.words)
	fmt.Println(copy(n.words, s.words))
	return n
}

func main() {
	var x, y IntSet
	x.Add(1)
	x.Add(144)
	x.Add(9)
	fmt.Println(x.String())

	y.Add(9)
	y.Add(42)
	fmt.Println(y.String())

	x.UnionWith(&y)
	fmt.Println(x.String())
	fmt.Println(x.Has(9), y.Has(123))

	fmt.Println(&x)
	fmt.Println(x.String())
	fmt.Println(x)

	fmt.Println("==========")

	fmt.Println(x.Len())
	x.Remove(9)

	fmt.Println(x.String())

	//x.Clear()
	//fmt.Println(x.String())

	var m IntSet
	m.Add(1)
	m.Add(256)

	n := m.Copy()
	fmt.Println(n.String())
}
