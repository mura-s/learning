package ch4

import (
	"testing"
)

func TestIsBalanced(t *testing.T) {
	root := createBlancedTree()
	if !IsBlanced(root) {
		t.Errorf("Not Balanced")
	}
}

func TestIsNotBalanced(t *testing.T) {
	root := createNotBlancedTree()
	if IsBlanced(root) {
		t.Errorf("Balanced")
	}
}

func createBlancedTree() *TreeNode {
	node5 := &TreeNode{5, nil, nil}
	node4 := &TreeNode{4, nil, nil}
	node3 := &TreeNode{3, nil, nil}
	node2 := &TreeNode{2, node4, node5}
	node1 := &TreeNode{1, node2, node3}
	return node1
}

func createNotBlancedTree() *TreeNode {
	node5 := &TreeNode{5, nil, nil}
	node4 := &TreeNode{4, nil, nil}
	//node3 := &TreeNode{3, nil, nil}
	node2 := &TreeNode{2, node4, node5}
	node1 := &TreeNode{1, node2, nil}
	return node1
}
