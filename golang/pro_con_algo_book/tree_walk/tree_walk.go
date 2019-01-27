package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Node node
type Node struct {
	ID     int
	Parent *Node
	Left   *Node
	Right  *Node
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)

	nodes := make([]*Node, n)
	for i := range nodes {
		nodes[i] = &Node{ID: i}
	}
	parse(sc, nodes, n)

	fmt.Println("Preorder")
	preorder(nodes[0])
	fmt.Println("")

	fmt.Println("Inorder")
	inorder(nodes[0])
	fmt.Println("")

	fmt.Println("Inorder")
	postorder(nodes[0])
	fmt.Println("")
}

func parse(sc *bufio.Scanner, nodes []*Node, n int) {
	for i := 0; i < n; i++ {
		id := nextInt(sc)
		leftID := nextInt(sc)
		rightID := nextInt(sc)
		node := nodes[id]

		if leftID != -1 {
			left := nodes[leftID]
			node.Left = left
			left.Parent = node
		}
		if rightID != -1 {
			right := nodes[rightID]
			node.Right = right
			right.Parent = node
		}
	}
}

func preorder(node *Node) {
	if node == nil {
		return
	}
	fmt.Printf(" %d", node.ID)
	preorder(node.Left)
	preorder(node.Right)
}

func inorder(node *Node) {
	if node == nil {
		return
	}
	inorder(node.Left)
	fmt.Printf(" %d", node.ID)
	inorder(node.Right)
}

func postorder(node *Node) {
	if node == nil {
		return
	}
	postorder(node.Left)
	postorder(node.Right)
	fmt.Printf(" %d", node.ID)
}
