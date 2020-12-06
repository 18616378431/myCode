package main

import (
	"fmt"
	"github.com/gorilla/mux"
	"log"
	"net/http"
)

func sayHello(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	w.WriteHeader(http.StatusOK)
	fmt.Fprintf(w, "Hello %s！", params["name"])
}

type HelloWorldHandler struct {

}

func (h *HelloWorldHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	w.WriteHeader(http.StatusOK)
	fmt.Fprintf(w, "你好,%s!", params["name"])
}

func main() {
	r := mux.NewRouter()
	//r.HandleFunc("/hello/{name}", sayHello)
	r.HandleFunc("/hello/{name:[a-z]+}", sayHello)

	r.Handle("/zh/hello/{name}", &HelloWorldHandler{})
	log.Fatal(http.ListenAndServe(":9091", r))
}
