package handlers

import (
	"encoding/base64"
	"encoding/json"
	"fmt"
	"net/http"
	"net/url"
	"time"
)

type Greet struct {
	Message string `json:"message"`
}

//写入数据到响应实体
//如果调用 Write 方法时还不知道 Content-Type，会通过数据的前 512 个字节进行判断。
func Home(w http.ResponseWriter, r *http.Request) {
	//io.WriteString(w, "Welcome to my blog site")
	//w.Write([]byte("欢饮访问学院君个人网站"))

	//返回html
//	html := `<html>
//		<head>
//			<title>学院君个人网站</title>
//		</head>
//		<body>
//			<h1>欢迎访问学院君个人网站</h1>
//		</body>
//</html>`
//	w.Write([]byte(html))

	//返回json格式数据
	greeting := Greet{
		"欢迎访问学院君个人网站",
	}
	w.Header().Set("Content-Type", "application/json")
	message, _ := json.Marshal(greeting)
	w.Write(message)
}

func Error(w http.ResponseWriter, r *http.Request) {
	w.WriteHeader(401)
	fmt.Fprintln(w, "认证后才能访问该接口")
}

//另外需要注意的是 w.Header().Set 必须在 w.WriteHeader 之前调用，因为一旦调用 w.WriteHeader 之后，就不能对响应头进行设置了
func Redirect(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Location", "http://www.baidu.com")
	w.WriteHeader(301)
}

//发送 Cookie 到客户端
func SetCookie(w http.ResponseWriter, r *http.Request) {
	c1 := http.Cookie{
		Name:"username",
		Value:url.QueryEscape("学院君"),
		HttpOnly:true,
		MaxAge:100,
	}
	c2 := http.Cookie{
		Name:"website",
		Value:"https://xueyuanjun.com",
		HttpOnly:true,
		Expires:time.Now().AddDate(0, 0, 1),
	}
	//w.Header().Add("Set-Cookie", c1.String())
	//w.Header().Add("Set-Cookie", c2.String())

	//setcookie便捷方法
	http.SetCookie(w, &c1)
	http.SetCookie(w, &c2)

	fmt.Println(time.Now().AddDate(0, 0, 1))

	fmt.Fprintln(w, "通过http响应头发送cookie信息")
}

//cookie := r.Header.Get("Cookie")
//但是这种方式读取的 Cookie 字符串值还需要进行解析，才能得到每个 Cookie 的值，
// 为此可以通过更加便捷的专门用于读取每个 Cookie 的 r.Cookie 方法
//如果想要一次性获取所有 Cookie，还可以通过 r.Cookies() 方法，该方法会返回的是 Cookie 对象指针类型切片
//cookies := r.Cookies()
//c1 := cookies[0]  // username=%E5%AD%A6%E9%99%A2%E5%90%9B
//c2 := cookies[1]  // website=https://xueyuanjun.com
func GetCookie(w http.ResponseWriter, r *http.Request) {
	c1, err := r.Cookie("username")
	if err != nil {
		fmt.Fprintln(w, "名为username的cookie不存在")
		return
	}
	username, _ := url.QueryUnescape(c1.Value)

	c2, err := r.Cookie("website")
	if err != nil {
		fmt.Fprintln(w, "名为website的cookie不存在")
		return
	}
	website := c2.Value
	fmt.Fprintf(w, "从用户请求中读取的cookie : {username:%s,website:%s}\n", username, website)
}

//删除 Cookie
//MaxAge: -1,
//Expires: time.Unix(1, 0),    // Cookie 有效期设置为过去的时间
func DeleteCookie(w http.ResponseWriter, r *http.Request) {
	c2 := http.Cookie{
		Name:"website",
		Value:"http://xueyuanjun.com",
		HttpOnly:true,
		MaxAge:-1,
	}
	c2 = http.Cookie{
		Name:"website",
		Value:"http://xueyuanjun.com",
		HttpOnly:true,
		Expires:time.Unix(1, 0),
	}
	http.SetCookie(w, &c2)
	fmt.Fprintln(w, "删除cookie")
}

//使用 Cookie 设置一次性消息
func SetWelcomeMessage(w http.ResponseWriter, r *http.Request) {
	msg := "欢迎访问学院君网站"
	cookie := http.Cookie{
		Name:"welcome_message",
		Value:base64.URLEncoding.EncodeToString([]byte(msg)),
	}
	http.SetCookie(w, &cookie)
	http.Redirect(w, r, "/get_welcome_message", 302)
}

func GetWelcomeMessage(w http.ResponseWriter, r *http.Request) {
	cookie, err := r.Cookie("welcome_message")
	if err != nil {
		fmt.Fprintln(w, "没有在cookie中找到欢迎消息")
	} else {
		delCookie := http.Cookie{
			Name:"welcome_message",
			MaxAge:-1,
		}
		http.SetCookie(w, &delCookie)
		msg, _ := base64.URLEncoding.DecodeString(cookie.Value)
		fmt.Fprintln(w, string(msg))
	}
}
