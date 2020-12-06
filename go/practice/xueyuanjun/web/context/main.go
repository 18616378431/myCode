package main

import (
	"html/template"
	"log"
	"net/http"
)

func contextExample(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("context.html"))
	content := `I asked:<i>"What's up?'"</i>`
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
//不转义 HTML
func xss(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("tmpl.html"))
	if r.Method == "GET" {
		t.Execute(w, nil)
	} else {
		t.Execute(w, template.HTML(r.FormValue("comment")))
	}
}

func main() {
	http.HandleFunc("/context", contextExample)
	http.HandleFunc("/xss", xssAttackExample)
	http.HandleFunc("/xss1", xss)
	log.Fatal(http.ListenAndServe(":8080", nil))
}
