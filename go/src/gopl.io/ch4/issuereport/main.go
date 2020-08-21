package main

//./issuereport repo:golang/go is:open json decoder

import (
	"gopl.io/ch4/github"
	"text/template"
	"log"
	"os"
	"time"
)


func main() {
	const templ = `{{.TotalCount}} issues:
					{{range .Items}}-----------------------------
					Number:{{.Number}}
					User:{{.User.Login}}
					Title:{{.Title | printf "%.64s"}}
					Age:{{.CreateAt | daysAgo}} days
					{{end}}`

	report := template.Must(template.New("issueList").
		Funcs(template.FuncMap{"daysAgo" : daysAgo}).
		Parse(templ))

	result, err := github.SearchIssues(os.Args[1:])

	if err != nil {
		log.Fatal(err)
	}

	if err := report.Execute(os.Stdout, result); err != nil {
		log.Fatal(err)
	}
}

func daysAgo(t time.Time) int {
	return int(time.Since(t).Hours() / 24)
}


