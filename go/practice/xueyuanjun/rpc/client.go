package main

import (
	"fmt"
	"log"
	"net/rpc"
	"rpc/utils"
)

func main() {
	var serverAddress = "localhost"
	client, err := rpc.DialHTTP("tcp", serverAddress + ":8080")
	if err != nil {
		log.Fatal("建立与服务端连接失败", err)
	}

	args := &utils.Args{10, 10}
	var reply int

	//同步调用
	err = client.Call("MathService.Multiply", args, &reply)
	if err != nil {
		log.Fatal("调用远程方法MathService.Multiply失败", err)
	}

	fmt.Printf("%d * %d = %d\n", args.A, args.B, reply)

	//异步调用
	//args.B = 0
	divideCall := client.Go("MathService.Divide", args, &reply, nil)
	for {
		select {
		case <- divideCall.Done:
			fmt.Printf("%d / %d = %d\n", args.A, args.B, reply)
			return
		}
	}
}