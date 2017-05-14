package ch2

import (
	"testing"
)

func TestPalindromeWhenOddLength(t *testing.T) {
	n1, n2, n3, n4, n5 :=
		&Node{1, nil}, &Node{2, nil}, &Node{3, nil}, &Node{2, nil}, &Node{1, nil}
	n1.Next, n2.Next, n3.Next, n4.Next = n2, n3, n4, n5

	actual := IsPalindrome(n1)
	expected := true

	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}

func TestPalindromeWhenEvenLength(t *testing.T) {
	n1, n2, n3, n4, n5, n6 :=
		&Node{1, nil}, &Node{2, nil}, &Node{3, nil}, &Node{3, nil}, &Node{2, nil}, &Node{1, nil}
	n1.Next, n2.Next, n3.Next, n4.Next, n5.Next = n2, n3, n4, n5, n6

	actual := IsPalindrome(n1)
	expected := true

	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}

func TestNotPalindrome(t *testing.T) {
	n1, n2, n3, n4, n5 :=
		&Node{1, nil}, &Node{2, nil}, &Node{3, nil}, &Node{4, nil}, &Node{5, nil}
	n1.Next, n2.Next, n3.Next, n4.Next = n2, n3, n4, n5

	actual := IsPalindrome(n1)
	expected := false

	if actual != expected {
		t.Errorf("got %v, want %v", actual, expected)
	}
}
