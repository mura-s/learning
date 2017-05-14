package ch3

import (
	"testing"
)

func TestMinStack(t *testing.T) {
	stack := &MinStack{}
	stack.Push(7)
	stack.Push(2)
	stack.Push(5)
	stack.Push(4)

	if min := stack.Min(); min != 2 {
		t.Errorf("got %v, want %v", min, 2)
	}

	if val := stack.Pop(); val != 4 {
		t.Errorf("got %v, want %v", val, 4)
	}

	if min := stack.Min(); min != 2 {
		t.Errorf("got %v, want %v", min, 2)
	}

	if val := stack.Pop(); val != 5 {
		t.Errorf("got %v, want %v", val, 5)
	}

	if val := stack.Pop(); val != 2 {
		t.Errorf("got %v, want %v", val, 2)
	}

	if min := stack.Min(); min != 7 {
		t.Errorf("got %v, want %v", min, 7)
	}
}
