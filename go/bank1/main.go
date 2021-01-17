package main

var deposits = make(chan int)//发送存款余额
var balances = make(chan int)//接收余额

func Deposit(amount int) {
	deposits <- amount
}

func Balance() int {
	return <- balances
}

func teller() {
	var balance int//通过通道访问监控goroutine中的局部变量
	for {
		select {
		case amount := <- deposits:
			balance += amount
		case balances <- balance:
		}
	}
}

func init() {
	go teller()
}

func main() {
	
}


