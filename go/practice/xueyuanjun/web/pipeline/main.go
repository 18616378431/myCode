package main

import (
	"html/template"
	"log"
	"net/http"
	"time"
)

func pipeline(w http.ResponseWriter, r *http.Request) {
	t := template.Must(template.ParseFiles("pipeline.html"))
	t.Execute(w, 12.3456)
}

func formatDate(t time.Time) string {
	layouts := "2006-01-02 15:04:05"
	return t.Format(layouts)
}

func customFunctionExample(w http.ResponseWriter, r *http.Request) {
	funcMap := template.FuncMap{
		"fdate":formatDate,
	}
	t := template.New("function.html").Funcs(funcMap)
	t,_  = t.ParseFiles("function.html")
	t.Execute(w, time.Now())
}

func main() {
	http.HandleFunc("/pipeline", pipeline)
	http.HandleFunc("/format", customFunctionExample)
	log.Fatal(http.ListenAndServe(":8080", nil))
}
