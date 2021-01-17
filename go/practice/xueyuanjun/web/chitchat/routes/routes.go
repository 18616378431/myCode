package routes

import (
	"chitchat/handlers"
	"net/http"
)

type WebRoute struct {
	Name string
	Method string
	Pattern string
	HandlerFunc http.HandlerFunc
}

//声明WebRoutes切片 存放所有web路由
type WebRoutes []WebRoute

//定义所有web路由
var webRoutes = WebRoutes{
	{
		"home",
		"GET",
		"/",
		handlers.Index,
	},
	{
		"signup",
		"GET",
		"/signup",
		handlers.Signup,
	},
	{
		"signupAccount",
		"POST",
		"/signup_account",
		handlers.SignupAccount,
	},
	{
		"login",
		"GET",
		"/login",
		handlers.Login,
	},
	{
		"auth",
		"POST",
		"/authenticate",
		handlers.Authenticate,
	},
	{
		"logout",
		"GET",
		"/logout",
		handlers.Logout,
	},
	{
		"newThread",
		"GET",
		"/thread/new",
		handlers.NewThread,
	},
	{
		"create thread",
		"POST",
		"/thread/create",
		handlers.CreateThread,
	},
	{
		"read thread",
		"GET",
		"/thread/read",
		handlers.ReadThread,
	},
	{
		"postThread",
		"POST",
		"/thread/post",
		handlers.PostThread,
	},
	{
		"error",
		"GET",
		"/err",
		handlers.Err,
	},
}