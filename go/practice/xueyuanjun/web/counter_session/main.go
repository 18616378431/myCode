package main

import (
	"github.com/gorilla/sessions"
	"html/template"
	"log"
	"net/http"
	"os"
)

//基于cookie存储
//var store = sessions.NewCookieStore([]byte(os.Getenv("SESSION_KEY")))

// 初始化存储器 文件存储
var store = sessions.NewFilesystemStore("session", []byte(os.Getenv("SESSION_KEY)")))

func counter(w http.ResponseWriter, r *http.Request) {
	session, _ := store.Get(r, "GOSESSID")
	count := session.Values["count"]
	if count == nil {
		session.Values["count"] = 1
	} else {
		session.Values["count"] = count.(int) + 1
	}
	err := session.Save(r, w)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
	t, _ := template.ParseFiles("counter.gtpl")
	w.Header().Set("Content-Type", "text/html")
	t.Execute(w, session.Values["count"])
}

func main() {
	http.HandleFunc("/counter", counter)
	log.Fatal(http.ListenAndServe(":8080", nil))
}
