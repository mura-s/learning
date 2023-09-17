package ch4

import "container/list"

func IsBST(root *TreeNode) bool {
	list := list.New()
	createOrderedArray(root, list)

	prev := list.Front()
	for e := prev.Next(); e != nil; e = e.Next() {
		if prev.Value.(int) > e.Value.(int) {
			return false
		}
		prev = e
	}

	return true
}

func createOrderedArray(root *TreeNode, list *list.List) {
	if root == nil {
		return
	}

	createOrderedArray(root.left, list)
	list.PushBack(root.value)
	createOrderedArray(root.right, list)
}
