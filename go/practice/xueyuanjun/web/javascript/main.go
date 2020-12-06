package main

import (
	"encoding/json"
	"github.com/gorilla/csrf"
	"github.com/gorilla/mux"
	"net/http"
)

type User struct {
	Id string `json:"id"`
	Name string `json:"name"`
	Website string `json:"website"`
}

func main() {
	r := mux.NewRouter()

	//设置路由前缀
	api := r.PathPrefix("/api").Subrouter()
	//在子路由上应用中间件
	api.Use(csrf.Protect([]byte("251e79cd5d1a994c51fd316f7040f13d")))
	// 如果客户端 JavaScript 应用部署在其他域名，需要通过 csrf.TrustedOrigins 设置服务端信任的客户端域名列表
	//api.Use(csrf.Protect([]byte("251e79cd5d1a994c51fd316f7040f13d"), csrf.TrustedOrigins([]string{"cli.domain.com"})))
	api.HandleFunc("/user/{id}", GetUser).Methods("GET")
	http.ListenAndServe(":8080", r)
}

func GetUser(w http.ResponseWriter, r *http.Request) {
	id := r.FormValue("id")
	user := User{Id:id, Name:"wjk", Website:"website"}

	//获取令牌设置到响应头
	// 这样一来，咱们的 JSON 客户端或者 JavaScript 框架就可以读取响应头获取 CSRF 令牌值
	// 然后在后续发送 POST 请求时就可以通过 X-CSRF-Token 请求头中带上这个 CSRF 令牌
	w.Header().Set("X-CSRF-Token", csrf.Token(r))
	b, err := json.Marshal(user)
	if err != nil {
		http.Error(w, err.Error(), 500)
		return
	}
	w.Write(b)
}
