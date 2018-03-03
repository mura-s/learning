package ch3

import (
	"testing"
)

func TestMyQueue(t *testing.T) {
	q := NewMyQueue()
	q.Enqueue(0)
	q.Enqueue(1)
	q.Enqueue(2)

	for i := 0; i < 3; i++ {
		if val := q.Dequeue(); val != i {
			t.Errorf("got %v, want %v", val, i)
		}
	}
}
