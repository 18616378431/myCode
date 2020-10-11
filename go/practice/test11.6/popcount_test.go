package main

import "testing"

const bin = 0x1234567890ABCDEF

func BenchmarkPopCount(b *testing.B) {
	for i := 0; i < b.N; i++ {
		PopCount(bin)
	}
}

func BenchmarkBitCount(b *testing.B) {
	for i := 0; i < b.N; i++ {
		BitCount(bin)
	}
}

func BenchmarkClearing(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Clearing(bin)
	}
}

func BenchmarkShifting(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Shifting(bin)
	}
}