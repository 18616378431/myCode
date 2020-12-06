//http https
/**
通过 OpenSSL 生成自签名证书
这里我们在本地演示 HTTPS 请求的处理，可以通过 OpenSSL 工具生成自签名证书：

# Generate CA private key
openssl genrsa -out ca.key 2048
# Generate CSR
openssl req -new -key ca.key -out ca.csr
# Generate Self Signed certificate（CA 根证书）
openssl x509 -req -days 365 -in ca.csr -signkey ca.key -out ca.crt
如果是通过 IP 地址访问 HTTPS 服务，红框内(Common Name)的部分请填写 IP 地址，
比如 127.0.0.1，如果通过域名访问，
可以将其设置为域名：

https://127.0.0.1:8443/hello?name=学院君
 */
package main

import (
	"fmt"
	"log"
	"net/http"
)

func main() {
	http.HandleFunc("/hello", hello)
	log.Fatal(http.ListenAndServeTLS("localhost:8443", "./ca.crt", "./ca.key", nil))
}

func hello(w http.ResponseWriter, r *http.Request) {
	params := r.URL.Query()
	n, _ := fmt.Fprintf(w, "你好, %s\n", params.Get("name"))
	fmt.Printf("Write %d bytes to client\n", n)
}
