package main

var (
	sema = make(chan struct{}, 1)//二进制信号量,同一时间只有一个goroutine访问共享变量
	balance int
)

func Deposit(amount int) {
	sema <- struct{}{}//获取令牌
	balance = balance + amount
	<- sema//释放令牌
}

func Balance() int {
	sema <- struct{}{}
	b := balance
	<- sema
	return b
}

func main() {
	
}
