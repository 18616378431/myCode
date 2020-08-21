package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
)

type client chan <- string//对外发送消息的通道

var (
	entering = make(chan client)
	leaving = make(chan client)
	message = make(chan string)//所有接收的客户端的消息
)

func main() {
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}
	go broadcaster()
	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err)
			continue
		}
		go handleConn(conn)
	}
}

func broadcaster() {
	clients := make(map[client]bool)//连接的客户端集合
	for {
		select {
		case msg := <- message:
			//将接收的消息广播给客户
			for cli := range clients {
				cli <- msg
			}
		case cli := <- entering:
			clients[cli] = true
		case cli := <- leaving:
			delete(clients, cli)
			close(cli)
		}
	}
}

func handleConn(conn net.Conn) {
	ch := make(chan string)
	go clientWriter(conn, ch)

	who := conn.RemoteAddr().String()
	ch <- "You are " + who
	entering <- ch
	message <- who + " has arrived"

	input := bufio.NewScanner(conn)
	for input.Scan() {
		message <- who + ":" + input.Text()
	}

	leaving <- ch
	message <- who + " has left"
	conn.Close()
}

func clientWriter(conn net.Conn, ch <- chan string) {
	for msg := range ch {
		fmt.Fprintln(conn, msg)
	}
}
