package main

import (
	"db_mysql1/mysql"
	"fmt"
)

func main() {
	//insert
	post := mysql.Post{
		Title:"Golang数据库编程",
		Content:"通过 go-sql-driver/mysql 包进行表之间的关联查询",
		Author:"学院君",
	}
	post.Create()

	//comments
	comment1 := mysql.Comment{
		Content:"测试评论1",
		Author:"学院君",
		Post:&post,
	}
	comment1.Create()

	comment2 := mysql.Comment{
		Content:"测试评论2",
		Author:"学院君",
		Post:&post,
	}
	comment2.Create()

	//查询文章评论信息
	mysqlPost, _ := mysql.GetPost(post.Id)
	fmt.Println(mysqlPost)
	fmt.Println(mysqlPost.Comments)
	fmt.Println(mysqlPost.Comments[0].Post)
}
