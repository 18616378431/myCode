package main

import (
	"fmt"
	"job/runner"
	"log"
	"os"
	"time"
)

const timeout = 3 * time.Second

func main() {
	fmt.Println("开始运行")

	r := runner.New(timeout)

	r.Add(createTask(), createTask(), createTask())

	if err := r.Start(); err != nil {
		switch err {
		case runner.ErrTimeout:
			log.Println("作业程序因超时而终止")
			os.Exit(1)
		case runner.ErrInterrupt:
			log.Println("作业程序因系统中断的终止")
			os.Exit(2)
		}
	}
}

func createTask() func(int) {
	return func(id int) {
		log.Printf("Processor - Task #%d.", id)
		time.Sleep(time.Duration(id) * time.Second)
	}
}