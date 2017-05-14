package main

import "fmt"

var (
	deposits = make(chan int)
	balances = make(chan int)
)

func Deposit(amount int) { deposits <- amount }

func Balance() int { return <-balances }

func teller() {
	var balance int
	for {
		select {
		case amount := <-deposits:
			balance += amount
			fmt.Println("from depositos")
		case balances <- balance:
			fmt.Println("to balances")
		}
	}
}

func main() {
	go teller()

	Deposit(100)
	Balance()
	Deposit(200)
	Balance()
}
