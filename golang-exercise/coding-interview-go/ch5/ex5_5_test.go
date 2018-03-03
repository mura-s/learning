package ch5

import (
	"testing"
)

func TestBitSwapRequired(t *testing.T) {
	actual := BitSwapRequired(64, 3)

	expected := 3

	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}

}
