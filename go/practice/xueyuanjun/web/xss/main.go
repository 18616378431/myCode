package main

//template上下文感知

import (
	"html/template"
	"log"
	"net/http"
)

func contextExample(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("context.html"))
	content := "I asked:<i>What's up?</i>"
	t.Execute(w, content)
}

func xssAttackExample(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("xss.html"))
	if r.Method == "GET" {
		t.Execute(w, nil)
	} else {
		t.Execute(w, r.FormValue("comment"))
	}
}

func main() {
	http.HandleFunc("/context", contextExample)
	http.HandleFunc("/xss", xssAttackExample)
	log.Fatal(http.ListenAndServe(":8080", nil))
}
