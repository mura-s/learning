package ch3

// イヌかネコが入るキュー
type DogCatQueue struct {
	dogs  *AnimalQueue
	cats  *AnimalQueue
	order int
}

func (queue *DogCatQueue) Enqueue(animal Animal) {
	animal.SetOrder(queue.order)
	queue.order++

	switch animal.(type) {
	case *Dog:
		{
			queue.dogs.Enqueue(animal)
		}
	case *Cat:
		{
			queue.cats.Enqueue(animal)
		}
	default:
		{
			panic("paramerter animal should be dog or cat")
		}
	}
}

func (queue *DogCatQueue) DequeueAny() Animal {
	dog := queue.dogs.Peek()
	cat := queue.cats.Peek()

	if dog.Order() < cat.Order() {
		return queue.DequeueDog()
	} else {
		return queue.DequeueCat()
	}
}

func (queue *DogCatQueue) DequeueDog() *Dog {
	return queue.dogs.Dequeue().(*Dog)
}

func (queue *DogCatQueue) DequeueCat() *Cat {
	return queue.cats.Dequeue().(*Cat)
}

// Queue
type AnimalQueue struct {
	buf []Animal
}

func (queue *AnimalQueue) Enqueue(animal Animal) {
	queue.buf = append(queue.buf, animal)
}

func (queue *AnimalQueue) Dequeue() Animal {
	value := queue.buf[0]
	queue.buf = queue.buf[1:len(queue.buf)]
	return value
}

func (queue *AnimalQueue) Peek() Animal {
	return queue.buf[0]
}

func (queue *AnimalQueue) IsEmpty() bool {
	return len(queue.buf) == 0
}

// Animal
type Animal interface {
	Order() int
	SetOrder(o int)
	Name() string
}

type animal struct {
	order int
	name  string
}

func (animal *animal) Order() int {
	return animal.order
}

func (animal *animal) SetOrder(o int) {
	animal.order = o
}

func (animal *animal) Name() string {
	return animal.name
}

type Dog struct {
	*animal
}

type Cat struct {
	*animal
}

func NewDog(name string) *Dog {
	return &Dog{&animal{name: name}}
}

func NewCat(name string) *Cat {
	return &Cat{&animal{name: name}}
}
