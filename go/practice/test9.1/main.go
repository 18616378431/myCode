package main

import "fmt"

type draw struct {
	amount int
	succeed chan bool
}

var deposits = make(chan int)//发送存款余额
var balances = make(chan int)//接收余额
var withDraws = make(chan draw)

func Deposit(amount int) {
	deposits <- amount
}

func Balance() int {
	return <- balances
}

func WithDraw(amount int) bool {
	succeed := make(chan bool)
	withDraws <- draw{amount, succeed}
	return <- succeed
}

func teller() {
	var balance int//通过通道访问监控goroutine中的局部变量
	for {
		select {
		case amount := <- deposits:
			balance += amount
		case balances <- balance:
		case draw := <-withDraws:
			if draw.amount <= balance {
				balance -= draw.amount
				draw.succeed <- true
			} else {
				draw.succeed <- false
			}
		}
	}
}

func init() {
	go teller()
}

func main() {
	fmt.Println(Balance())
	Deposit(300)
	fmt.Println(Balance())
	fmt.Println(WithDraw(50))
	fmt.Println(Balance())
}


