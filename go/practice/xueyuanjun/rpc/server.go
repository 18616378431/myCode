/**
一个对象只有满足以下这些条件的方法，才能被 RPC 服务端设置为可提供远程访问：

必须是在对象外部可公开调用的方法（首字母大写）；
必须有两个参数，且参数的类型都必须是包外部可以访问的类型或者是 Go 内建支持的类型；
第二个参数必须是一个指针；
方法必须返回一个 error 类型的值。

以上 4 个条件，可以简单地用如下这行代码表示：
func (t *T) MethodName(argType T1, replyType *T2) error
 */
package main

import (
	"errors"
	"fmt"
	"log"
	"net"
	"net/http"
	"net/rpc"
	"rpc/utils"
)

type MathService struct {

}

func (m *MathService) Multiply(args *utils.Args, reply *int) error {
	fmt.Println("Multiply")
	*reply = args.A * args.B
	return nil
}

func (m *MathService) Divide(args *utils.Args, reply *int) error {
	fmt.Println("Divide")
	if args.B == 0 {
		return errors.New("除数不能为0")
	}
	*reply = args.A / args.B
	return nil
}

func main() {
	math := new(MathService)

	rpc.Register(math)
	rpc.HandleHTTP()

	listener, err := net.Listen("tcp", ":8080")
	if err != nil {
		log.Fatal("启动服务监听失败", err)
	}

	err = http.Serve(listener, nil)
	if err != nil {
		log.Fatal("启动HTTP服务失败", err)
	}
}