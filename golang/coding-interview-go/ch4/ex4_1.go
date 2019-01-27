package ch4

import "math"

type TreeNode struct {
	value int
	left  *TreeNode
	right *TreeNode
}

func IsBlanced(root *TreeNode) bool {
	if root == nil {
		return true
	}

	heightDiff := getHeight(root.left) - getHeight(root.right)
	if math.Abs(float64(heightDiff)) > 1 {
		return false
	} else {
		return IsBlanced(root.left) && IsBlanced(root.right)
	}
}

func getHeight(root *TreeNode) int {
	if root == nil {
		return 0
	}

	return int(math.Max(float64(getHeight(root.left)),
		float64(getHeight(root.right)))) + 1
}
