package ch4

import (
	"testing"
)

func TestIsBST(t *testing.T) {
	array := []int{1, 2, 3, 3, 4, 5, 6}
	root := CreateMinTree(array)
	if !IsBST(root) {
		t.Errorf("is not BST")
	}

	n3 := &TreeNode{1, nil, nil}
	n2 := &TreeNode{1, nil, nil}
	n1 := &TreeNode{3, n2, n3}
	if IsBST(n1) {
		t.Errorf("is BST")
	}
}
