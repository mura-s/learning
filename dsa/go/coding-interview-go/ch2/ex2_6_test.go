package ch2

import (
	"testing"
)

func TestCirculationNode(t *testing.T) {
	n1, n2, n3, n4, n5 :=
		&Node{1, nil}, &Node{2, nil}, &Node{3, nil}, &Node{4, nil}, &Node{5, nil}
	n1.Next, n2.Next, n3.Next, n4.Next, n5.Next = n2, n3, n4, n5, n3

	actual := DetectCirculationNode(n1)
	expected := n3

	if actual.Item != expected.Item {
		t.Errorf("got %v, want %v", actual.Item, expected.Item)
	}
}
