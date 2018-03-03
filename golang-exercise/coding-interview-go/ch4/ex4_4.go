package ch4

import "container/list"

func CreateLevelList(root *TreeNode) []*list.List {
	lists := []*list.List{}
	current := list.New()
	if root != nil {
		current.PushBack(root)
	}

	for current.Len() > 0 {
		lists = append(lists, current)
		parents := current
		current = list.New()

		for e := parents.Front(); e != nil; e = e.Next() {
			left, right := e.Value.(*TreeNode).left, e.Value.(*TreeNode).right
			if left != nil {
				current.PushBack(left)
			}
			if right != nil {
				current.PushBack(right)
			}
		}
	}

	return lists
}
