package main

import (
	"html/template"
	"log"
	"net/http"
)

func bench(w http.ResponseWriter, r *http.Request) {
	t, _ := template.ParseFiles("views/index.html")
	t.Execute(w, nil)
}

func main() {
	http.HandleFunc("/", bench)
	log.Fatal(http.ListenAndServe(":9091", nil))
}
