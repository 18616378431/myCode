package handlers

import (
	"github.com/gorilla/mux"
	"io"
	"net/http"
)

func GetUser(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	id := params["id"]
	io.WriteString(w, "Return user info with id " + id)
}