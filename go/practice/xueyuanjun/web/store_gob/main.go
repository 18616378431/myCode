package main

import (
	"bytes"
	"encoding/gob"
	"fmt"
	"io/ioutil"
)

type Article struct {
	Id int
	Title string
	Content string
	Author string
}

func write(data interface{}, filename string) {
	buffer := new(bytes.Buffer)
	encoder := gob.NewEncoder(buffer)
	err := encoder.Encode(data)
	if err != nil {
		panic(err)
	}
	err = ioutil.WriteFile(filename, buffer.Bytes(), 0644)
	if err != nil {
		panic(err)
	}
}

func read(data interface{}, filename string) {
	raw, err := ioutil.ReadFile(filename)
	if err != nil {
		panic(err)
	}
	buffer := bytes.NewBuffer(raw)
	dec := gob.NewDecoder(buffer)
	err = dec.Decode(data)
	if err != nil {
		panic(err)
	}
}

func main() {
	article := Article{
		Id:1,
		Title:"Gob",
		Content:"基于gob编解码",
		Author:"学院君",
	}
	write(article, "article_data")
	var articleData Article
	read(&articleData, "article_data")
	fmt.Printf("%#v\n", articleData)
}
