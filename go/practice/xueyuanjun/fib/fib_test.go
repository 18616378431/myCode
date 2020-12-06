package main

import "testing"

func BenchmarkFibnacci(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Fibnacci(5)
	}
}

func BenchmarkMemFibnacci(b *testing.B) {
	for i := 0; i < b.N; i++ {
		MemFibnacci(5)
	}
}