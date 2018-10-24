package main

import (
	"fmt"
	"log"

	"github.com/gofrs/uuid"
)

func main() {
	u2, err := uuid.NewV4()
	if err != nil {
		log.Fatalf("failed to generate UUID: %v", err)
	}
	fmt.Println(u2.String())
}
