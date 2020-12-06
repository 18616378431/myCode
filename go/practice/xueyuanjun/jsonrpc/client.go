package main

import (
	"jsonrpc/utils"
	"log"
	"net"
	"net/rpc/jsonrpc"
	"time"
)

func main() {
	conn, err := net.DialTimeout("tcp", "localhost:8080", 30 * time.Second)
	if err != nil {
		log.Fatalf("客户端发起连接失败 : %v\n", err)
	}
	defer conn.Close()
	client := jsonrpc.NewClient(conn)
	var item utils.Item
	client.Call("ServiceHandler.GetName", 1, &item)
	log.Printf("ServiceHandler.GetName返回结果 : %v\n", item)

	var resp utils.Response
	item = utils.Item{2, "学院君2"}
	client.Call("ServiceHandler.SaveName", item, &resp)
	log.Printf("ServiceHandler.SaveName返回结果 : %v\n", resp)
}
