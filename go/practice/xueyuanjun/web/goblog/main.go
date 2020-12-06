package main

import (
	"goblog/routes"
	"log"
	"net/http"
)

func main() {
	startWebServer("8080")

}

func startWebServer(port string) {
	r := routes.NewRouter()
	http.Handle("/", r)

	log.Println("Starting HTTP service at " + port)
	err := http.ListenAndServe(":" + port, nil)
	if err != nil {
		log.Println("An error occured starting HTTP listen at port " + port)
		log.Println("Error : " + err.Error())
	}
}
