package ch1

import (
	"testing"
)

func TestUniqueString(t *testing.T) {
	actual := IsUniqueString("abcdefghi")
	expected := true
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}

func TestNotUniqueString(t *testing.T) {
	actual := IsUniqueString("ababab")
	expected := false
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
