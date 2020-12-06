package main

import (
	"fmt"
	"log"
	"net/http"
	"strings"
)

func sayHelloWorld(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	fmt.Println(r.Form)
	fmt.Println("URL:", r.URL.Path)
	fmt.Println("Scheme:", r.URL.Scheme)
	for k, v := range r.Form {
		fmt.Println(k, ":", strings.Join(v, ""))
	}
	fmt.Fprintf(w, "你好,学院君!")
}

func main() {
	http.HandleFunc("/", sayHelloWorld)
	err := http.ListenAndServe(":9091", nil)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}
}