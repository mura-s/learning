package ch4

import (
	"testing"
)

func TestContainsTree(t *testing.T) {
	n1 := &TreeNode{value: 1}
	n2 := &TreeNode{value: 2}
	n3 := &TreeNode{value: 3}
	n4 := &TreeNode{value: 4}

	n1.left = n2
	n2.left, n2.right = n3, n4

	m2 := &TreeNode{value: 2}
	m3 := &TreeNode{value: 3}
	m4 := &TreeNode{value: 4}

	m2.left, m2.right = m3, m4

	if !ContainsTree(n1, m2) {
		t.Errorf("Not contains")
	}
}
