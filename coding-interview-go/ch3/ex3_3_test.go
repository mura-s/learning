package ch3

import (
	"testing"
)

func TestSetOfStacks(t *testing.T) {
	set := &SetOfStacks{}
	set.Push(1)
	set.Push(2)
	set.Push(3)
	set.Push(4)
	set.Push(5)
	set.Push(6)
	set.Push(7)

	for i := 7; i > 0; i-- {
		if val := set.Pop(); val != i {
			t.Errorf("got %v, want %v", val, i)
		}
	}

	// 空になってからもPush可能か
	set.Push(1)
}
