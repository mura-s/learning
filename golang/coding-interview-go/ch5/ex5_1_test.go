package ch5

import (
	"testing"
)

func TestUpdateBits(t *testing.T) {
	actual := UpdateBits(1024, 19, 2, 6)
	expected := 1024 + 64 + 8 + 4
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
