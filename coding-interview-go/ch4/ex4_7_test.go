package ch4

import (
	"testing"
)

func TestCommonAncestor(t *testing.T) {
	n1 := &TreeNode{value: 1}
	n2 := &TreeNode{value: 2}
	n3 := &TreeNode{value: 3}
	n4 := &TreeNode{value: 4}

	n1.left = n2
	n2.left, n2.right = n3, n4

	if n := CommonAncestor(n1, n3, n4); n != n2 {
		t.Errorf("got %v, want %v", n.value, n2.value)
	}
}
