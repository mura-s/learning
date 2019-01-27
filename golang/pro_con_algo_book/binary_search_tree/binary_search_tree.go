package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Node node
type Node struct {
	Value  int
	Parent *Node
	Left   *Node
	Right  *Node
}

func next(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n, _ := strconv.Atoi(next(sc))
	var root *Node

	for i := 0; i < n; i++ {
		op := next(sc)
		switch op {
		case "insert":
			z, _ := strconv.Atoi(next(sc))
			if root == nil {
				root = &Node{Value: z}
			} else {
				insert(root, z)
			}
		case "print":
			print(root)
		}
	}
}

func insert(root *Node, z int) {
	var y *Node
	x := root

	for x != nil {
		y = x
		if z < x.Value {
			x = x.Left
		} else {
			x = x.Right
		}
	}

	node := &Node{Value: z, Parent: y}
	if node.Value < y.Value {
		y.Left = node
	} else {
		y.Right = node
	}
}

func print(root *Node) {
	inorder(root)
	fmt.Println("")
	preorder(root)
	fmt.Println("")
}

func inorder(node *Node) {
	if node == nil {
		return
	}
	inorder(node.Left)
	fmt.Printf(" %d", node.Value)
	inorder(node.Right)
}

func preorder(node *Node) {
	if node == nil {
		return
	}
	fmt.Printf(" %d", node.Value)
	preorder(node.Left)
	preorder(node.Right)
}
