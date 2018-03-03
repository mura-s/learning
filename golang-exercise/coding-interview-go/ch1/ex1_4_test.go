package ch1

import (
	"testing"
)

func TestReplaceWhiteSpace(t *testing.T) {
	actual := ReplaceWhiteSpace("Mr John Smith   ")
	expected := "Mr%20John%20Smith"
	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
