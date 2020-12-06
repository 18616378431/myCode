package main

import (
	"html/template"
	"log"
	"math/rand"
	"net/http"
	"time"
)

func layoutExample(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("layout.html"))
	t.ExecuteTemplate(w, "layout", "")
}

func layoutExample1(w http.ResponseWriter, r *http.Request) {
	rand.Seed(time.Now().Unix())
	var t *template.Template
	if rand.Intn(10) > 5 {
		t = template.Must(template.ParseFiles("layout.html", "hello_blue.html"))
	} else {
		//t = template.Must(template.ParseFiles("layout.html", "hello_red.html"))
		t = template.Must(template.ParseFiles("layout.html"))
	}
	t.ExecuteTemplate(w, "layout", "")
}

func main() {
	http.HandleFunc("/layout", layoutExample)
	http.HandleFunc("/layout1", layoutExample1)
	log.Fatal(http.ListenAndServe(":8080", nil))
}