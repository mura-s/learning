package ch4

import (
	"testing"
)

func TestInorderSucc(t *testing.T) {
	n1 := &TreeNode2{value: 1}
	n2 := &TreeNode2{value: 2}
	n3 := &TreeNode2{value: 3}
	n4 := &TreeNode2{value: 4}

	n1.left = n2
	n2.parent = n1
	n2.left, n2.right = n3, n4
	n3.parent, n4.parent = n2, n2

	if InorderSucc(n1) != nil {
		t.Errorf("InorderSucc(n1) != nil")
	}

	if InorderSucc(n2) != n4 {
		t.Errorf("InorderSucc(n2) != n4")
	}

	if InorderSucc(n3) != n2 {
		t.Errorf("InorderSucc(n3) != n2")
	}

	if InorderSucc(n4) != n1 {
		t.Errorf("InorderSucc(n4) != n1")
	}
}
