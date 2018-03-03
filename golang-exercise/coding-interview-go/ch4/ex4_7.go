package ch4

func covers(root *TreeNode, p *TreeNode) bool {
	if root == nil {
		return false
	}
	if root == p {
		return true
	}
	return covers(root.left, p) || covers(root.right, p)
}

func commonAncestorHelper(root *TreeNode, p *TreeNode, q *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	if root == p || root == q {
		return root
	}

	pOnLeft := covers(root.left, p)
	qOnLeft := covers(root.left, q)

	if pOnLeft != qOnLeft {
		return root
	}

	var child_side *TreeNode
	if pOnLeft {
		child_side = root.left
	} else {
		child_side = root.right
	}
	return commonAncestorHelper(child_side, p, q)
}

func CommonAncestor(root *TreeNode, p *TreeNode, q *TreeNode) *TreeNode {
	return commonAncestorHelper(root, p, q)
}
