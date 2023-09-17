package ch1

import (
	"testing"
)

func TestRotate(t *testing.T) {
	n := 5
	actual := [][]int{{1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 3, 3, 3, 3}, {4, 4, 4, 4, 4}, {5, 5, 5, 5, 5}}
	Rotate(actual, n)
	expected := [][]int{{5, 4, 3, 2, 1}, {5, 4, 3, 2, 1}, {5, 4, 3, 2, 1}, {5, 4, 3, 2, 1}, {5, 4, 3, 2, 1}}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if actual[i][j] != expected[i][j] {
				t.Errorf("got %v, want %v", actual, expected)
				return
			}
		}
	}
}
