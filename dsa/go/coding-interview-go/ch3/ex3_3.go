package ch3

const EachStackSize = 5

// 複数のStackを持ち、スタックが一杯になったらスタックを新たに作る。
type SetOfStacks struct {
	stacks []*Stack
}

func (set *SetOfStacks) Push(value int) {
	if len(set.stacks) == 0 {
		set.stacks = []*Stack{&Stack{}}
	}

	if len(set.tailStack().buf) > EachStackSize {
		set.stacks = append(set.stacks, &Stack{})
	}

	set.tailStack().Push(value)
}

func (set *SetOfStacks) Pop() int {
	value := set.tailStack().Pop()

	if len(set.tailStack().buf) == 0 {
		set.stacks = set.stacks[0 : len(set.stacks)-1]
	}

	return value
}

func (set *SetOfStacks) tailStack() *Stack {
	if len(set.stacks) == 0 {
		return nil
	}

	return set.stacks[len(set.stacks)-1]
}
