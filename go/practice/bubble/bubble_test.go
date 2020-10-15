package main

import "testing"

/**
Test Result

1.临时变量交换值
wangjiankang:bubble wangjiankang$ go test -bench=.
goos: darwin
goarch: amd64
BenchmarkOldBubble-4            29431550                43.5 ns/op
BenchmarkNewBubble-4            51403545                26.1 ns/op
BenchmarkBestBubble-4           86564421                15.3 ns/op
PASS
ok      _/Users/wangjiankang/Downloads/go/practice/bubble       4.039s

2.平行赋值
wangjiankang:bubble wangjiankang$ go test -bench=.
goos: darwin
goarch: amd64
BenchmarkOldBubble-4            30312093                42.7 ns/op
BenchmarkNewBubble-4            52141754                24.9 ns/op
BenchmarkBestBubble-4           79796528                14.9 ns/op
PASS
ok      _/Users/wangjiankang/Downloads/go/practice/bubble       3.870s

 */

func BenchmarkOldBubble(b *testing.B) {
	for i := 0; i < b.N; i++ {
		OldBubble()
	}
}

func BenchmarkNewBubble(b *testing.B) {
	for i := 0; i < b.N; i++ {
		NewBubble()
	}
}

func BenchmarkBestBubble(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Best()
	}
}