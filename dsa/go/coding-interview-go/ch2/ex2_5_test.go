package ch2

import (
	"testing"
)

func TestAddTwoNode(t *testing.T) {
	n1, n2, n3 := &Node{7, nil}, &Node{1, nil}, &Node{6, nil}
	n1.Next, n2.Next = n2, n3

	m1, m2, m3 := &Node{5, nil}, &Node{9, nil}, &Node{2, nil}
	m1.Next, m2.Next = m2, m3

	actual := AddTwoNode(n1, m1)

	ex1, ex2, ex3 := &Node{2, nil}, &Node{1, nil}, &Node{9, nil}
	ex1.Next, ex2.Next = ex2, ex3

	for ; actual != nil && ex1 != nil; actual, ex1 = actual.Next, ex1.Next {
		if actual.Item != ex1.Item {
			t.Errorf("got %v, want %v", actual.Item, ex1.Item)
		}
	}
}
