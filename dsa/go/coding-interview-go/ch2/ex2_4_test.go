package ch2

import (
	"testing"
)

func TestMoveSmallerNode(t *testing.T) {
	n1, n2, n3, n4, n5 := &Node{5, nil}, &Node{2, nil}, &Node{3, nil}, &Node{4, nil}, &Node{1, nil}
	n1.Next, n2.Next, n3.Next, n4.Next = n2, n3, n4, n5
	n1 = MoveSmallerNode(n1, 3)

	m1, m2, m3, m4, m5 := &Node{2, nil}, &Node{1, nil}, &Node{5, nil}, &Node{3, nil}, &Node{4, nil}
	m1.Next, m2.Next, m3.Next, m4.Next = m2, m3, m4, m5

	for i1, i2 := n1, m1; i1.Next != nil && i2.Next != nil; i1, i2 = i1.Next, i2.Next {
		if i1.Item != i2.Item {
			t.Errorf("got %v, want %v", i1.Item, i2.Item)
		}
	}
}

func TestNoSmallerNode(t *testing.T) {
	n1, n2, n3, n4, n5 := &Node{5, nil}, &Node{4, nil}, &Node{3, nil}, &Node{4, nil}, &Node{4, nil}
	n1.Next, n2.Next, n3.Next, n4.Next = n2, n3, n4, n5
	n1 = MoveSmallerNode(n1, 3)

	m1, m2, m3, m4, m5 := &Node{5, nil}, &Node{4, nil}, &Node{3, nil}, &Node{4, nil}, &Node{4, nil}
	m1.Next, m2.Next, m3.Next, m4.Next = m2, m3, m4, m5

	for i1, i2 := n1, m1; i1.Next != nil && i2.Next != nil; i1, i2 = i1.Next, i2.Next {
		if i1.Item != i2.Item {
			t.Errorf("got %v, want %v", i1.Item, i2.Item)
		}
	}
}
