package main

import "fmt"

type Post struct {
	Id int
	Title string
	Content string
	Author string
}

var PostsById map[int]*Post
var PostsByAuthor map[string][]*Post

//添加post实例到字典
func store(post Post) {
	PostsById[post.Id] = &post
	PostsByAuthor[post.Author] = append(PostsByAuthor[post.Author], &post)
}

func main() {
	//初始化字典
	PostsById = make(map[int]*Post)
	PostsByAuthor = make(map[string][]*Post)

	//初始化文章信息
	post1 := Post{Id:1, Title:"PHP全栈工程师指南", Content:"基于Laravel+Vue.js开发Web项目", Author:"学院君"}
	post2 := Post{Id:2, Title:"Go入门教程", Content:"Go语言基础语法和使用指南", Author:"学院君"}
	post3 := Post{Id:3, Title:"Go Web编程", Content:"基于Gin框架构建Web项目", Author:"学院君"}
	post4 := Post{Id:4, Title:"微服务从入门到实战", Content:"基于Laravel+go-micro框架构建微服务", Author:"学院君"}

	//添加字段
	store(post1)
	store(post2)
	store(post3)
	store(post4)

	fmt.Println(PostsById[1])
	fmt.Println(PostsById[2])

	fmt.Println("----")

	for _, post := range PostsByAuthor["学院君"] {
		fmt.Println(post)
	}

	//修改数据
	PostsById[1].Author = "学院君小号"
	delete(PostsByAuthor, "学院君")

	fmt.Println(PostsById[1])
	for _, post := range PostsByAuthor["学院君"] {
		fmt.Println(post)
	}
}
