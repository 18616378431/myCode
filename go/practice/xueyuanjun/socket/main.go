//socket
/**
./socket www.baidu.com:80
HTTP/1.0 302 Found
Content-Length: 17931
Content-Type: text/html
Date: Sun, 25 Oct 2020 08:26:18 GMT
Etag: "54d97487-460b"
Server: bfe/1.0.8.18
 */
package main

import (
	"bytes"
	"fmt"
	"io"
	"net"
	"os"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Fprintf(os.Stderr, "Usage : %s host:port", os.Args[0])
		os.Exit(1)
	}
	service := os.Args[1]
	conn, err := net.Dial("tcp", service)
	CheckError(err)

	_, err = conn.Write([]byte("HEAD / HTTP/1.0\r\n\r\n"))
	//_, err = conn.Write([]byte("GET / HTTP/1.0\r\n\r\n"))
	CheckError(err)

	result, err := ReadFully(conn)
	CheckError(err)

	fmt.Println(string(result))

	os.Exit(0)
}

func CheckError(err error) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "Fatal error : %s\n", err.Error())
		os.Exit(1)
	}
}

func ReadFully(conn net.Conn) ([]byte, error) {
	//读取所有响应数据并关闭连接
	defer conn.Close()
	result := bytes.NewBuffer(nil)
	var buf [512]byte
	for {
		n, err := conn.Read(buf[0:])
		result.Write(buf[0:n])
		if err != nil {
			if err == io.EOF {
				break
			}
			return nil, err
		}
	}
	return result.Bytes(), nil
}