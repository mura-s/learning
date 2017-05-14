package ch4

import "fmt"

func FindSum(node *TreeNode, sum int) {
	findSum(node, sum, []int{}, 0)
}

func findSum(node *TreeNode, sum int, path []int, level int) {
	if node == nil {
		return
	}

	path = append(path, node.value)

	tmp := 0
	for i := level; i >= 0; i-- {
		tmp += path[i]
		if tmp == sum {
			print(path, i, level)
		}
	}

	findSum(node.left, sum, path, level+1)
	findSum(node.right, sum, path, level+1)
}

func print(path []int, start, end int) {
	for i := start; i <= end; i++ {
		fmt.Printf("%d ", path[i])
	}
	fmt.Println()
}
