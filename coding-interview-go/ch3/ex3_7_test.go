package ch3

import (
	"testing"
)

func TestAnimalQueue(t *testing.T) {
	dogsAndCats := &DogCatQueue{
		&AnimalQueue{},
		&AnimalQueue{},
		0,
	}

	dogsAndCats.Enqueue(NewDog("dog1"))
	dogsAndCats.Enqueue(NewCat("cat1"))
	dogsAndCats.Enqueue(NewDog("dog2"))
	dogsAndCats.Enqueue(NewCat("cat2"))

	if name := dogsAndCats.DequeueAny().Name(); name != "dog1" {
		t.Errorf("got %v, want %v", name, "dog1")
	}

	if name := dogsAndCats.DequeueAny().Name(); name != "cat1" {
		t.Errorf("got %v, want %v", name, "cat1")
	}

	if name := dogsAndCats.DequeueDog().Name(); name != "dog2" {
		t.Errorf("got %v, want %v", name, "dog2")
	}

	if name := dogsAndCats.DequeueCat().Name(); name != "cat2" {
		t.Errorf("got %v, want %v", name, "cat2")
	}
}
