package main

import (
	"html/template"
	"log"
	"net/http"
)

/**
ab -c 10 -n 10000 http://127.0.0.1:8080/hello
 */

func main() {
	http.HandleFunc("/hello", hello)
	log.Fatal(http.ListenAndServe(":8080", nil))
}

func hello(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("index.html"))
	tt := "123"
	t.Execute(w, tt)
	//fmt.Fprint(w, "Hello World!")
}
