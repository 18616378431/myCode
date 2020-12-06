package main

import (
	"jsonrpc/utils"
	"log"
	"net"
	"net/rpc"
	"net/rpc/jsonrpc"
)

type ServiceHandler struct {

}

func (serviceHandler *ServiceHandler) GetName(id int, item *utils.Item) error {
	log.Printf("receive GetName call, id : %d\n", id)
	item.Id = id
	item.Name = "学院君"
	return nil
}

func (ServiceHandler *ServiceHandler) SaveName(item utils.Item, resp *utils.Response) error {
	log.Printf("receive SaveName call, Item : %v\n", item)
	resp.Ok = true
	resp.Id = item.Id
	resp.Message = "存储成功"
	return nil
}

func main() {
	//初始化rpc服务端
	server := rpc.NewServer()

	//监听8080
	listener, err := net.Listen("tcp", ":8080")
	if err != nil {
		log.Fatalf("监听端口失败 : %v\n", err)
	}
	defer listener.Close()

	log.Println("Start listen on port localhost:8080")

	//初始化服务处理器
	serviceHandler := &ServiceHandler{}
	//注册
	err = server.Register(serviceHandler)
	if err != nil {
		log.Fatalf("注册服务处理器失败 : %v\n", err)
	}

	//等待客户端连接
	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Fatalf("接收客户端连接请求失败 : %v\n", err)
		}

		//自定义RPC编码器,新建一个jsonrpc编码器并绑定到rpc服务端处理器
		go server.ServeCodec(jsonrpc.NewServerCodec(conn))
	}
}
