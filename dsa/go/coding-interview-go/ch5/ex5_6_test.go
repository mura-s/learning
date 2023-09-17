package ch5

import (
	"testing"
)

func TestSwapOddEvenBits(t *testing.T) {
	actual := SwapOddEvenBits(37)

	expected := uint16(26)

	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}

}
