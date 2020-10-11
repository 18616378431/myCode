package main

//TZ=Europe/London ./test8.1 -port 8020 &
//TZ=Asia/Tokyo ./test8.1 -port 8030 &
//TZ=US/Eastern ./test8.1 -port 8010 &

import (
	"flag"
	"fmt"
	"io"
	"log"
	"net"
	"time"
)

var port = flag.String("port", "8000", "port")

func main() {
	flag.Parse()
	listen := "localhost:" + *port
	fmt.Println("listen on :" + listen)
	listener, err := net.Listen("tcp", listen)
	if err != nil {
		log.Fatal(err)
	}
	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err)
			continue
		}
		go handleConn(conn)
	}
}

func handleConn(c net.Conn) {
	defer c.Close()
	for {
		_, err := io.WriteString(c, time.Now().Format("15:04:05\n"))
		if err != nil {
			return
		}
		time.Sleep(1 * time.Second)
	}
}
