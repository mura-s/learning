package ch4

func CreateMinTree(array []int) *TreeNode {
	return CreateTree(array, 0, len(array)-1)
}

func CreateTree(array []int, start, end int) *TreeNode {
	if start > end {
		return nil
	}

	mid := (start + end) / 2
	node := &TreeNode{array[mid], nil, nil}
	node.left = CreateTree(array, start, mid-1)
	node.right = CreateTree(array, mid+1, end)

	return node
}
