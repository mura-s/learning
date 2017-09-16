package sub

import (
	"fmt"
	"os"
	"testing"
)

func TestMain(m *testing.M) {
	fmt.Println("test")
	code := m.Run()
	os.Exit(code)
}

func TestSub(t *testing.T) {
	data := []struct {
		i, j, expected int
	}{
		{3, 2, 1},
		{5, 3, 2},
	}

	for idx, d := range data {
		actual := Sub(d.i, d.j)
		if actual != d.expected {
			t.Errorf("index %d: got %v, want %v", idx, actual, d.expected)
		}
	}
}
