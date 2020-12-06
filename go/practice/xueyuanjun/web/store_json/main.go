package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type Book struct {
	Id int `json:"id"`
	Title string `json:"title"`
	Summary string `json:"summary"`
	Author	string `json:"author"`
}

func main() {
	var books map[int]*Book = make(map[int]*Book)
	book1 := Book{Id:1, Title:"Go Web编程", Summary:"Go Web编程指南", Author:"学院君"}
	books[book1.Id] = &book1

	//Json序列化
	data, _ := json.Marshal(books)

	//将data写入到当前目录下的books文件,文件不存在则创建
	//err := ioutil.WriteFile("books", data, 0644)
	file, _ := os.Create("books1")
	defer file.Close()
	_, err := file.Write(data)
	if err != nil {
		panic(err)
	}

	//dataEncoded, _ := ioutil.ReadFile("books")
	file1, _ := os.Open("books1")
	defer file1.Close()
	dataEncoded := make([]byte, len(data))
	file1.Read(dataEncoded)
	//将读取到的json数据反序列化为原来的类型
	var bookDecoded map[int]*Book
	json.Unmarshal(dataEncoded, &bookDecoded)
	fmt.Printf("%#v\n", bookDecoded[book1.Id])
}
