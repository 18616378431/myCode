package routes

import (
	"github.com/gorilla/mux"
	"net/http"
)

func NewRouter() *mux.Router {
	router := mux.NewRouter().StrictSlash(true)

	//请求日志中间件 http://localhost:8080/posts?page=1#comments
	router.Use(loggingRequestInfo)

	for _, route := range webRoutes {
		router.Methods(route.Method).
			Path(route.Pattern).
			Name(route.Name).
			Handler(route.HandlerFunc)
	}

	return router
}

func loggingRequestInfo(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		//打印请求url明细
		//url, _ := json.Marshal(r.URL)
		//log.Println(string(url))

		//打印请求日志
		//请求头和响应头都通过 Header 字段表示，Header 是一个键值对字典，键是字符串，值是字符串切片
		//Header.Get Add Set
		//fmt.Printf("Request URL : %s\n", r.URL)
		//fmt.Printf("User Agent : %s\n", r.Header.Get("User-Agent"))
		//fmt.Printf("Request Header : %v\n", r.Header)

		next.ServeHTTP(w, r)
	})
}