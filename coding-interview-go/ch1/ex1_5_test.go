package ch1

import (
	"testing"
)

func TestCompressString(t *testing.T) {
	actual := CompressString("aabcccccaaa")
	expected := "a2b1c5a3"
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}

func TestCompressReturnOriginalString(t *testing.T) {
	actual := CompressString("abcdefg")
	expected := "abcdefg"
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
