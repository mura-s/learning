package ch4

import (
	"container/list"
	"testing"
)

func TestCreateLevelList(t *testing.T) {
	array := []int{1, 2, 3, 3, 4, 5, 6}
	root := CreateMinTree(array)
	lists := CreateLevelList(root)

	l1, l2, l3 := list.New(), list.New(), list.New()
	l1.PushBack(3)
	l2.PushBack(2)
	l2.PushBack(5)
	l3.PushBack(1)
	l3.PushBack(3)
	l3.PushBack(4)
	l3.PushBack(6)

	expectedLists := []*list.List{l1, l2, l3}

	for i := 0; i < len(lists); i++ {
		actual, expected := lists[i].Front(), expectedLists[i].Front()

		for actual != nil {
			if actual.Value.(*TreeNode).value != expected.Value {
				t.Errorf("got %v, want %v", actual.Value.(*TreeNode).value, expected.Value)
			}
			actual, expected = actual.Next(), expected.Next()
		}
	}
}
