package ch3

import (
	"testing"
)

func TestHanoi(t *testing.T) {
	tower1 := &Stack{[]int{4, 3, 2, 1, 0}}
	tower2, tower3 := &Stack{}, &Stack{}
	Hanoi(tower1, tower2, tower3)

	for i := 4; i >= 0; i-- {
		if val := tower3.buf[4-i]; val != i {
			t.Errorf("got %v, want %v", val, i)
		}
	}
}
