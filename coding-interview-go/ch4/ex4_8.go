package ch4

func ContainsTree(t1, t2 *TreeNode) bool {
	if t2 == nil {
		return true
	}
	return subTree(t1, t2)
}

func subTree(t1, t2 *TreeNode) bool {
	if t1 == nil {
		return false
	}

	if t1.value == t2.value {
		if matchTree(t1, t2) {
			return true
		}
	}

	return subTree(t1.left, t2) || subTree(t1.right, t2)
}

func matchTree(t1, t2 *TreeNode) bool {
	if t1 == nil && t2 == nil {
		return true
	}
	if t1 == nil || t2 == nil {
		return false
	}
	if t1.value != t2.value {
		return false
	}

	return matchTree(t1.left, t2.left) && matchTree(t1.right, t2.right)
}
