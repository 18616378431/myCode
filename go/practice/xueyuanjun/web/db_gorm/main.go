package main

import (
	"fmt"
	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/mysql"
	"time"
)

type Post struct {
	Id int
	Title string
	Content string
	Author string `sql:"not null"`
	CreatedAt time.Time
	Comments []Comment
}

type Comment struct {
	Id int
	Content string
	Author string `sql:"not null"`
	PostId int `sql:"index"`
	CreatedAt time.Time
}

var DbConn *gorm.DB

func init() {
	var err error
	DbConn, err = gorm.Open("mysql", "root:root@tcp(localhost:3306)/test_db?charset=utf8mb4&parseTime=true")
	if err != nil {
		panic(err)
	}
	DbConn.AutoMigrate(&Post{}, &Comment{})
}

func main() {
	post := Post{
		Title:"GORM示例",
		Content:"基于 GORM 进行数据库增删改查",
		Author:"学院君",
	}

	//insert
	DbConn.Create(&post)
	fmt.Println(post)

	//通过关联关系新增评论并将其附加到对应的文章记录
	comment := Comment{
		Content:"Test Comment",
		Author:"学院君",
	}
	DbConn.Model(&post).Association("Comments").Append(comment)

	//查询文章记录
	var gormPost Post
	DbConn.Where("author = ?", "学院君").First(&gormPost)

	//查询包含评论数据的文章记录
	var comments []Comment
	DbConn.Model(&gormPost).Related(&comments)
	fmt.Println(comments[0])
}
