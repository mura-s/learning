package ch3

import (
	"testing"
)

func TestStack(t *testing.T) {
	stack := NewThreeStack()
	stack.Push(1, 0)
	stack.Push(2, 0)
	stack.Push(3, 1)
	stack.Push(4, 2)

	actual := [4]int{stack.Pop(0), stack.Pop(0), stack.Pop(1), stack.Peek(2)}
	expected := [4]int{2, 1, 3, 4}

	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
