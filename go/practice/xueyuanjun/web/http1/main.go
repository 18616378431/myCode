//自定义请求处理器
package main

import (
	"fmt"
	"net/http"
)

type MyHandler struct {

}

func (m *MyHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	SayGoLang(w, r)
}

func SayGoLang(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello Golang!")
}

type WorldGolang struct {

}

func (wg *WorldGolang) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello World!")
}

func main() {
	handler := MyHandler{}
	world := WorldGolang{}
	server := http.Server{
		Addr:":9091",
	}
	http.Handle("/hello", &handler)
	http.Handle("/world", &world)
	server.ListenAndServe()
}
