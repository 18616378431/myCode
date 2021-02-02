package handlers

import (
	"chitchat/models"
	"net/http"
)

//首页论坛处理器方法
func Index(w http.ResponseWriter, r *http.Request) {
	//files := []string{"views/layout.html", "views/navbar.html", "views/index.html"}
	//templates := template.Must(template.ParseFiles(files...))
	//threads, err := models.Threads()
	//if err == nil {
	//	templates.ExecuteTemplate(w, "layout", threads)
	//}
	threads, err := models.Threads()
	if err == nil {
		_, err := session(w, r)
		if err != nil {
			generateHTML(w, threads, "layout", "navbar", "index")
		} else {
			generateHTML(w, threads, "layout", "auth.navbar", "index")
		}
	}
}

//error render
func Err(writer http.ResponseWriter, request *http.Request) {
	vals := request.URL.Query()
	_, err := session(writer, request)
	if err != nil {
		generateHTML(writer, vals.Get("msg"), "layout", "navbar", "error")
	} else {
		generateHTML(writer, vals.Get("msg"), "layout", "auth.navbar", "error")
	}
}

