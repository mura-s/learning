package gotest

import "testing"

func TestAdd(t *testing.T) {
	const i, j, out = 1, 2, 3
	if x := Add(i, j); x != out {
		t.Errorf("Add(%v, %v) = %v, want %v", i, j, x, out)
	}
}
