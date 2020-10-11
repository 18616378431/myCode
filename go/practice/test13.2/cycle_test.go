package main

import "testing"

func TestCycle(t *testing.T) {
	type Node struct {
		value string
		next *Node
	}

	//cycle
	cycle1 := &Node{"cycle1", nil}
	cycle2 := &Node{"cycle2", nil}
	cycle3 := &Node{"cycle3", nil}
	cycle1.next = cycle2
	cycle2.next = cycle3
	cycle3.next = cycle1

	if got, want := Cycle(cycle1), true; got != want {
		t.Errorf("got %v, want %v", got, want)
	}

	line := &Node{"line1", &Node{"line2", &Node{"line3", nil}}}
	if got, want := Cycle(line), false; got != want {
		t.Errorf("got %v, want %v", got, want)
	}
}