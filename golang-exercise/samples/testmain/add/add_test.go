package add

import (
	"fmt"
	"os"
	"testing"
)

func TestMain(m *testing.M) {
	fmt.Println("main1")
	code := m.Run()
	os.Exit(code)
}

func TestAdd(t *testing.T) {
	data := []struct {
		i, j, expected int
	}{
		{1, 2, 3},
		{1, 3, 4},
	}

	for idx, d := range data {
		actual := Add(d.i, d.j)
		if actual != d.expected {
			t.Errorf("index %d: got %v, want %v", idx, actual, d.expected)
		}
	}
}
