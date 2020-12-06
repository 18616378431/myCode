package main

import (
	"bytes"
	"encoding/gob"
	"fmt"
	"log"
)

type P struct {
	X, Y, Z int
	Name string
	Tags []string
	Attr map[string]string
}

type Q struct {
	X, Y *int32
	Name string
	Tags []string
	Attr map[string]string
}

func main() {
	var network bytes.Buffer
	enc := gob.NewEncoder(&network)
	dec := gob.NewDecoder(&network)

	//数据编码
	err := enc.Encode(P{3, 4, 5, "学院君", []string{"PHP", "Laravel", "Go"}, map[string]string{"website" : "https://xueyuanjun.com"}})
	if err != nil {
		log.Fatal("encode error:", err)
	}

	//数据解码
	var q Q
	err = dec.Decode(&q)
	if err != nil {
		log.Fatal("decode error:", err)
	}

	fmt.Printf("%q : {%d, %d}, Tags : %v, Attr : %v\n", q.Name, *q.X, *q.Y, q.Tags, q.Attr)
}