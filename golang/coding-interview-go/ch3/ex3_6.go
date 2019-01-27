package ch3

// スタック上のデータを小さい順に並び替える
func SortStack(stack *Stack) *Stack {
	distStack := &Stack{}

	for !stack.isEmpty() {
		val := stack.Pop()
		for !distStack.isEmpty() && distStack.Peek() < val {
			stack.Push(distStack.Pop())
		}
		distStack.Push(val)
	}

	return distStack
}
