package main

import "sync"

var (
	mu sync.Mutex
	balance int
)

func Deposit(amount int) {
	mu.Lock()
	defer mu.Unlock()
	deposit(amount)
}

func Balance() int {
	mu.Lock()
	defer mu.Unlock()
	return balance
}

//已获得互斥锁
func deposit(amount int) {
	balance += amount
}

func Withdraw(amount int) bool {
	mu.Lock()
	defer mu.Unlock()
	deposit(-amount)
	if balance < 0 {//余额不足
		deposit(amount)
		return false
	}
	return true
}

func main() {
	
}
