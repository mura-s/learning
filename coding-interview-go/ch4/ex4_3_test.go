package ch4

import (
	"testing"
)

func TestCreateTree(t *testing.T) {
	array := []int{1, 2, 3, 3, 4, 5, 6}
	root := CreateMinTree(array)

	actual := [7]int{
		root.value,
		root.left.value,
		root.right.value,
		root.left.left.value,
		root.left.right.value,
		root.right.left.value,
		root.right.right.value,
	}

	expected := [7]int{3, 2, 5, 1, 3, 4, 6}

	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
