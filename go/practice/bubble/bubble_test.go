package main

import "testing"

/**
Test Result
wangjiankang:bubble wangjiankang$ go test -bench=.
goos: darwin
goarch: amd64
BenchmarkOldBubble-4            29431550                43.5 ns/op
BenchmarkNewBubble-4            51403545                26.1 ns/op
BenchmarkBestBubble-4           86564421                15.3 ns/op
PASS
ok      _/Users/wangjiankang/Downloads/go/practice/bubble       4.039s

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