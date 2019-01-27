package ch1

import (
	"testing"
)

func TestSortedString(t *testing.T) {
	actual := IsSortedString("abcde", "edcba")
	expected := true
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}

func TestNotSortedString(t *testing.T) {
	actual := IsSortedString("abcde", "aaaaa")
	expected := false
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}

func TestDifferentLenString(t *testing.T) {
	actual := IsSortedString("abcde", "abcdeabc")
	expected := false
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
