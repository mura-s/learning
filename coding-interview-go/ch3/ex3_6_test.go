package ch3

import (
	"testing"
)

func TestSortStack(t *testing.T) {
	stack := &Stack{}
	stack.Push(5)
	stack.Push(3)
	stack.Push(1)
	stack.Push(2)
	stack.Push(4)
	result := SortStack(stack)

	for i := 1; i <= 5; i++ {
		if val := result.Pop(); val != i {
			t.Errorf("got %v, want %v", val, i)
		}
	}
}
