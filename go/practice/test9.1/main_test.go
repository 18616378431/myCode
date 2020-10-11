package main

import (
	"sync"
	"testing"
)

func TestWithDrawConCurrent(t *testing.T) {
	Deposit(10000)

	var wg sync.WaitGroup
	for i := 0; i < 100; i++ {
		wg.Add(1)
		go func(amount int) {
			WithDraw(amount)
			wg.Done()
		}(i)
	}

	wg.Wait()

	if got, want := Balance(), 5050; got != want {
		t.Errorf("got %v, want %v", got, want)
	}
}
