package ch1

import (
	"testing"
)

func TestSetZero(t *testing.T) {
	actual := [][]int{{1, 1, 1, 1, 1}, {2, 2, 2, 0, 2}, {0, 3, 3, 3, 3}}
	SetZeroToMatrix(actual)
	expected := [][]int{{0, 1, 1, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}

	for i := 0; i < 3; i++ {
		for j := 0; j < 5; j++ {
			if actual[i][j] != expected[i][j] {
				t.Errorf("got %v, want %v", actual, expected)
				return
			}
		}
	}
}
