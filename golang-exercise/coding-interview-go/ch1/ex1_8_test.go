package ch1

import (
	"testing"
)

func TestRotateString(t *testing.T) {
	actual := IsRotateString("waterbottle", "erbottlewat")
	expected := true
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}

func TestNotRotateString(t *testing.T) {
	actual := IsRotateString("waterbottle", "aabottlewat")
	expected := false
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}

func TestDifferentLengthString(t *testing.T) {
	actual := IsRotateString("waterbottle", "errbottlewat")
	expected := false
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
