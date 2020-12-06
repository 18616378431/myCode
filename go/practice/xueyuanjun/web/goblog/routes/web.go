package routes

import (
	"goblog/handlers"
	"net/http"
)

//存放单个路由
type WebRoute struct {
	Name string
	Method string
	Pattern string
	HandlerFunc http.HandlerFunc
}

//声明WebRoutes切片存放所有Web路由
type WebRoutes []WebRoute

//定义所有web路由
var webRoutes = WebRoutes{
	WebRoute{
		"Home",
		"GET",
		"/",
		handlers.Home,
	},
	WebRoute{
		"Posts",
		"GET",
		"/posts",
		handlers.GeoPosts,
	},
	WebRoute{
		"User",
		"GET",
		"/user/{id}",
		handlers.GetUser,
	},
	//请求实体 curl -id "title=test&content=hello" http://localhost:8080/post/add
	WebRoute{
		"NewPost",
		"POST",
		"/post/add",
		handlers.AddPost,
	},
	//Form中存储了所有的请求信息
	//如果只想获取请求实体（即 POST 表单中的数据），可以通过 PostForm 实现
	//post表单和get数据
	//curl -X POST -id "title=test&content=hello" http://localhost:8080/post/edit?id=1
	WebRoute{
		"UpdatePost",
		"POST",
		"/post/edit",
		handlers.EditPost,
	},
	//curl -i http://localhost:8080/post/edit?id=1\&title=test\&content=hello
	WebRoute{
		"EditPost",
		"GET",
		"/post/edit",
		handlers.EditPost,
	},
	//图片上传
	WebRoute{
		"UploadImage",
		"POST",
		"/image/upload",
		handlers.UploadImage,
	},
	//error
	WebRoute{
		"ApiError",
		"GET",
		"/error",
		handlers.Error,
	},
	//redirect
	WebRoute{
		"Redirect",
		"GET",
		"/redirect",
		handlers.Redirect,
	},
	//set cookie
	WebRoute{
		"SetCookie",
		"GET",
		"/setcookie",
		handlers.SetCookie,
	},
	//get cookie
	WebRoute{
		"GetCookie",
		"GET",
		"/getcookie",
		handlers.GetCookie,
	},
	//delete cookie
	WebRoute{
		"DeleteCookie",
		"GET",
		"/deletecookie",
		handlers.DeleteCookie,
	},
	//message
	WebRoute{
		"SetMessage",
		"GET",
		"/set_welcome_message",
		handlers.SetWelcomeMessage,
	},
	WebRoute{
		"GetMessage",
		"GET",
		"/get_welcome_message",
		handlers.GetWelcomeMessage,
	},
}