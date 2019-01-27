package ch5

import (
	"testing"
)

func TestDrawHorizontalLine(t *testing.T) {
	screen := []byte{0, 0, 0, 0, 0, 0, 0, 0, 0}
	actual := DrawHorizontalLine(screen, 24, 5, 16, 1)
	expected := []byte{0, 0, 0, 7, 255, 128, 0, 0, 0}

	for i := 0; i < len(actual); i++ {
		if actual[i] != expected[i] {
			t.Errorf("got %v, want %v", actual[i], expected[i])
		}
	}
}
