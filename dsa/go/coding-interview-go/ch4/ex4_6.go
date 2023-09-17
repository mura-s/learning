package ch4

type TreeNode2 struct {
	value  int
	left   *TreeNode2
	right  *TreeNode2
	parent *TreeNode2
}

func InorderSucc(n *TreeNode2) *TreeNode2 {
	if n == nil {
		return nil
	}

	if n.parent == nil || n.right != nil {
		return leftMostChild(n.right)
	} else {
		q := n
		x := q.parent
		for x != nil && x.left != q {
			q = x
			x = x.parent
		}
		return x
	}
}

func leftMostChild(n *TreeNode2) *TreeNode2 {
	if n == nil {
		return nil
	}

	for n.left != nil {
		n = n.left
	}
	return n
}
