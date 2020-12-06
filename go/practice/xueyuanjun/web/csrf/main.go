package main

import (
	"github.com/gorilla/csrf"
	"github.com/gorilla/mux"
	"html/template"
	"net/http"
)

func main() {
	r := mux.NewRouter()
	r.HandleFunc("/signup", ShowSignupForm)
	//POST no CSRF field, return 403
	r.HandleFunc("/signup/post", SubmitSignupForm).Methods("POST")
	// 应用 csrf.Protect 中间件到路由器 r
	// 该函数第一个参数是 32 位长的认证密钥（任意字符做 MD5 元算即可），用于加密 CSRF 令牌
	// 本地开发基于 HTTP 协议，所以第二个参数通过 csrf.Secure(false) 进行标识
	http.ListenAndServe(":8080",
		csrf.Protect([]byte("251e79cd5d1a994c51fd316f7040f13d"), csrf.Secure(false))(r))
}

func ShowSignupForm(w http.ResponseWriter, r *http.Request) {
	//传递注入CSRF令牌的csrf.TemplateField函数到注册页面
	t := template.Must(template.ParseFiles("signup.html"))
	t.Execute(w, map[string]interface{}{
		csrf.TemplateTag:csrf.TemplateField(r),
	})
	// 我们还可以通过 csrf.Token(r) 直接获取令牌并将其设置到请求头：w.Header.Set("X-CSRF-Token", token)
	// 这在发送 JSON 响应到客户端或者前端 JavaScript 框架时很有用
}

func SubmitSignupForm(w http.ResponseWriter, r *http.Request) {

}
