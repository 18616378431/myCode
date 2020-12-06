package main

import (
	"html/template"
	"log"
	"net/http"
)

func process(w http.ResponseWriter, r *http.Request) {
	t, _ := template.ParseFiles("tmpl.html")
	t.Execute(w, "Hello World!")
}

func parseString(w http.ResponseWriter, r *http.Request) {
	tmpl := `<!DOCTYPE html>
<html lang="en">
<head>
    <meta http-equiv="Content-Type" content="text/html" t charset="UTF-8">
    <title>{{ . }}</title>
</head>
<body>
{{ . }}
</body>
</html>`
	t := template.New("tmpl.html")
	t.Parse(tmpl)
	t.Execute(w, "Test Hello World!")
}

func main() {
	http.HandleFunc("/template", process)
	http.HandleFunc("/templ", parseString)
	log.Fatal(http.ListenAndServe(":8080", nil))
}
