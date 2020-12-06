package main

import (
	"fmt"
	"mosaic/common"
	"mosaic/concurrent"
	"mosaic/sync"
	"net/http"
)

func main() {
	mux := http.NewServeMux()
	files := http.FileServer(http.Dir("public"))
	mux.Handle("/static/", http.StripPrefix("/static/", files))
	mux.HandleFunc("/", sync.Upload)
	//mux.HandleFunc("/mosaic", sync.Mosaic)
	mux.HandleFunc("/mosaic", concurrent.Mosaic)
	server := &http.Server{
		Addr:"127.0.0.1:8080",
		Handler:mux,
	}
	//初始化嵌入图片数据库,以便处理图片时克隆
	common.TILESDB = common.TilesDB()

	fmt.Println("图片马赛克应用服务器已启动")
	server.ListenAndServe()
}
