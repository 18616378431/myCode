package main

//交叉编译
//GOOS=linux GOARCH=amd64 go build

import (
	"chitchat/config"
	"chitchat/routes"
	"log"
	"net/http"
)

func main() {
	startWebServer("8080")
}

//单例配置sync.Once
//func startWebServer(port string) {
//	//全局配置
//	conf := config.LoadConfig()
//	r := routes.NewRouter()
//	//处理静态文件
//	//http://localhost:8080/static/css/bootstrap.min.css
//	//deal : <application root>/public/css/bootstrap.min.css
//	assets := http.FileServer(http.Dir(conf.App.Static))
//	r.PathPrefix("/static/").Handler(http.StripPrefix("/static/", assets))
//	http.Handle("/", r)
//	log.Println("Starting http service at " + conf.App.Address)
//	err := http.ListenAndServe(conf.App.Address, nil)
//	if err != nil {
//		log.Println("An error occured starting http listener at " + conf.App.Address)
//		log.Println("Error : " + err.Error())
//	}
//}

func startWebServer(port string) {
	r := routes.NewRouter()
	//处理静态文件
	//http://localhost:8080/static/css/bootstrap.min.css
	//deal : <application root>/public/css/bootstrap.min.css
	assets := http.FileServer(http.Dir(config.ViperConfig.App.Static))
	r.PathPrefix("/static/").Handler(http.StripPrefix("/static/", assets))
	http.Handle("/", r)
	log.Println("Starting http service at " + config.ViperConfig.App.Address)
	err := http.ListenAndServe(config.ViperConfig.App.Address, nil)
	if err != nil {
		log.Println("An error occured starting http listener at " + config.ViperConfig.App.Address)
		log.Println("Error : " + err.Error())
	}
}