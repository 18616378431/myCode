package main

import (
	"bytes"
	"fmt"
)

// 当 uint 为 64 位时，64 个 1111111... 右移 63 位变成 1，32 再左移 1 位变成 64
// 当 uint 位 32 位时，32 个 1111111... 右移 63 位变成 0, 32 再左移 0 位 变成 32
const uintSize = 32 << (^uint(0) >> 63)

type IntSet struct {
	words []uint
}

//是否存在非负数
func (s *IntSet) Has(x int) bool {
	word, bit := x / uintSize, uint(x % uintSize)
	return word < len(s.words) && s.words[word] & (1 << bit) != 0
}

//添加非负数到集合
func (s *IntSet) Add(x int) {
	word, bit := x / uintSize, uint(x % uintSize)
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
		for j := 0; j < uintSize; j++ {
			if word & (1 << uint(j)) != 0 {
				if buf.Len() > len("{") {
					buf.WriteByte(' ')
				}
				fmt.Fprintf(&buf, "%d", uintSize * i + j)
			}
		}
	}
	buf.WriteByte('}')
	return buf.String()
}

func (s *IntSet) Len() int {
	count := 0
	for _, word := range s.words {
		for mask := uint(0); mask < uintSize; mask++ {
			if word & (1 << mask) != 0 {
				count++
			}
		}
	}
	return count
}

func (s *IntSet) Remove(x int) {
	word, bit := x / uintSize, uint(x % uintSize)
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

/**
copy无法将源slice中的值拷贝到新slice中
 */
func (s *IntSet) Copy() *IntSet {
	n := &IntSet{}
	fmt.Println(s.words)
	fmt.Println(copy(n.words, s.words))
	return n
}

func (s *IntSet) AddAll(vals ...int) {
	for _, v := range vals {
		s.Add(v)
	}
}

//intersect
func (s *IntSet) IntersectWith(t *IntSet) {
	minLen := len(s.words)
	if len(t.words) < minLen {
		minLen = len(t.words)
	}
	for i := 0; i < minLen; i++ {
		s.words[i] &= t.words[i]
	}
	s.words = s.words[:minLen]
}

//diff
func (s *IntSet) DiffWith(t *IntSet) {
	for i := range s.words {
		if i < len(t.words) {
			s.words[i] &^= t.words[i]
		}
	}

	for len(s.words) != 0 && s.words[len(s.words) - 1] == 0 {
		s.words = s.words[:len(s.words) - 1]
	}
}

//SymmetricDifference
func (s *IntSet) SymmetricDifference(t *IntSet) {
	for i, word := range t.words {
		if i < len(s.words) {
			s.words[i] ^= word
		} else {
			s.words = append(s.words, word)
		}
	}

	for len(s.words) != 0 && s.words[len(s.words) - 1] == 0 {
		s.words = s.words[:len(s.words) - 1]
	}
}

func (s *IntSet) Elems() []int {
	var elems []int
	for i, word := range s.words {
		for mask := uint(0); mask < uintSize; mask++ {
			if word & (1 << mask) != 0 {
				elems = append(elems, i * uintSize + int(mask))
			}
		}
	}
	return elems
}

func main() {
	var u,i IntSet
	u.AddAll(1, 255)
	i.AddAll(1, 2, 3, 4)

	fmt.Println(u.Elems())
}
