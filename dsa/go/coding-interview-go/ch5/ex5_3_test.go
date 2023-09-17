package ch5

import (
	"testing"
)

func TestGetNextAndPrev(t *testing.T) {
	a_next, a_prev := GetNextAndPrev(120)

	e_next, e_prev := 135, 116

	if a_next != e_next {
		t.Errorf("got %v, want %v", a_next, e_next)
	}

	if a_prev != e_prev {
		t.Errorf("got %v, want %v", a_prev, e_prev)
	}
}
