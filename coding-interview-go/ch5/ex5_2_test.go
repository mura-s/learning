package ch5

import (
	"testing"
)

func TestPrintBinary(t *testing.T) {
	actual := PrintBinary(0.625)
	expected := "0.101"
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
