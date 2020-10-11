package main

import (
	"fmt"
	"html/template"
	"log"
	"net/http"
	"strconv"
	"sync"
)

type dollars float32

func (d dollars) String() string {
	return fmt.Sprintf("$%.2f", d)
}

type database map[string]dollars

func (db database) list(w http.ResponseWriter, req *http.Request) {
	templ := template.Must(template.ParseFiles("index.html"))
	if err := templ.Execute(w, db); err != nil {
		log.Println(err)
	}
}

func (db database) price(w http.ResponseWriter, req *http.Request) {
	item := req.URL.Query().Get("item")
	price, ok := db[item]
	if !ok {
		w.WriteHeader(http.StatusNotFound)
		fmt.Fprintf(w, "no such item : %q\n", item)
		return
	}
	fmt.Fprintf(w, "%s\n", price)
}

var mu sync.Mutex

func (db database) update(w http.ResponseWriter, r *http.Request) {
	item := r.URL.Query().Get("item")
	price := r.URL.Query().Get("price")
	p, err := strconv.ParseFloat(price, 32)
	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		fmt.Fprintf(w, "param err : %v\n", err)
	}
	mu.Lock()
	_, ok := db[item]
	if !ok {
		w.WriteHeader(http.StatusNotFound)
		fmt.Fprintf(w, "item isn't exists!\n", item)
	} else {
		db[item] = dollars(p)
	}
	mu.Unlock()
}

func (db database) create(w http.ResponseWriter, r *http.Request) {
	item := r.URL.Query().Get("item")
	price := r.URL.Query().Get("price")
	p, err := strconv.ParseFloat(price, 32)
	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		fmt.Fprintf(w, "params err : %v\n", err)
	}
	mu.Lock()
	_, ok := db[item]
	if ok {
		w.WriteHeader(http.StatusNotFound)
		fmt.Fprintf(w, "%s has exists!\n", item)
	} else {
		db[item] = dollars(p)
	}
	mu.Unlock()
}

func (db database) read(w http.ResponseWriter, r *http.Request) {
	item := r.URL.Query().Get("item")
	p, ok := db[item]
	if !ok {
		w.WriteHeader(http.StatusNotFound)
		fmt.Fprintf(w, "%s not found!\n", item)
	} else {
		fmt.Fprintf(w, " %s : %.2f$\n", item, p)
	}
}

func (db database) delete(w http.ResponseWriter, r *http.Request) {
	item := r.URL.Query().Get("item")
	_, ok := db[item]
	if !ok {
		w.WriteHeader(http.StatusNotFound)
		fmt.Fprintf(w, "%s not found!\n", item)
	} else {
		mu.Lock()
		delete(db, item)
		mu.Unlock()
	}
}

func main() {
	db := database{"shoes" : 50, "socks" : 5}

	mux := http.NewServeMux()
	mux.Handle("/list", http.HandlerFunc(db.list))
	mux.Handle("/price", http.HandlerFunc(db.price))
	mux.Handle("/update", http.HandlerFunc(db.update))
	mux.Handle("/create", http.HandlerFunc(db.create))
	mux.Handle("/read", http.HandlerFunc(db.read))
	mux.Handle("/delete", http.HandlerFunc(db.delete))

	//第三个参数为nil时默认使用DefaultServeMux
	log.Fatal(http.ListenAndServe("localhost:8000", mux))

	//http.HandleFunc("/list", db.list)
	//http.HandleFunc("/price", db.list)
	//http.HandleFunc("/update", db.list)
	//http.HandleFunc("/create", db.list)
	//http.HandleFunc("/read", db.list)
	//http.HandleFunc("/delete", db.list)
	//
	//log.Fatal(http.ListenAndServe(":8000", nil))
}
