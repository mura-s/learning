package ch4

import (
	"testing"
)

func TestFindSum(t *testing.T) {
	n1 := &TreeNode{value: 0}
	n2 := &TreeNode{value: 1}
	n3 := &TreeNode{value: 2}
	n4 := &TreeNode{value: 3}

	n1.left = n2
	n2.left, n2.right = n3, n4

	FindSum(n1, 3)
}
