package ch5

import (
	"testing"
)

func TestFindMissingNum(t *testing.T) {
	array := []int{7, 1, 0, 2, 6, 3, 4}
	actual := FindMissingNum(array)
	expected := 5

	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}

}
