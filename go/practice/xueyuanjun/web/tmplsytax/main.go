package main

import (
	"html/template"
	"log"
	"math/rand"
	"net/http"
	"time"
)

func process(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("condition.html"))
	rand.Seed(time.Now().Unix())
	t.Execute(w, rand.Intn(10) > 5)
}

func iterationActionExample(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("iteration.html"))
	daysOfWeek := []string{"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"}
	t.Execute(w, daysOfWeek)
}

func setActionExample(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("set.html"))
	t.Execute(w, "golang")
}

func includeActionExample(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("t1.html", "t2.html"))
	t.Execute(w, "Hello World!")
}

func main() {
	http.HandleFunc("/condition", process)
	http.HandleFunc("/iteration", iterationActionExample)
	http.HandleFunc("/set", setActionExample)
	http.HandleFunc("/include", includeActionExample)
	log.Fatal(http.ListenAndServe(":8080", nil))
}
