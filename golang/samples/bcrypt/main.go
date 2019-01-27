package main

import (
	"fmt"

	"golang.org/x/crypto/bcrypt"
)

func main() {
	pass := []byte("mypassword")
	hashedPassword1, err := bcrypt.GenerateFromPassword(pass, bcrypt.DefaultCost)
	if err != nil {
		panic("error")
	}
	fmt.Println(string(hashedPassword1))
}
