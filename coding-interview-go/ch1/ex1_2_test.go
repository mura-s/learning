package ch1

import (
	"testing"
)

func TestReverse(t *testing.T) {
	str := []byte("reverse")
	Reverse(str)
	expected := []byte("esrever")

	if string(str) != string(expected) {
		t.Errorf("got %v, want %v", str, expected)
	}
}
