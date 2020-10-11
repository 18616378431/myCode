package main

import (
	"fmt"
	"github.com/gin-gonic/gin"
	_ "github.com/go-sql-driver/mysql"
	"github.com/jinzhu/gorm"
	"net/http"
)

var db *gorm.DB
var err error

func main() {
	r := gin.Default()
	r.GET("/", func(c *gin.Context) {
		c.String(http.StatusOK, "Hello World")
	})
	r.Run()

	handle()
}

type User struct {
	ID   int
	Name string
	Age  int
	City string
}

func handle() {
	db, err = gorm.Open("mysql", "root:root@tcp(127.0.0.1:3306)/go_mysql?charset=utf8")

	if err != nil {
		fmt.Println(err)
		return
	} else {
		fmt.Println("数据库连接成功")
	}

	defer db.Close()

	//创建表
	db.AutoMigrate(&User{})

	//创建记录
	//user1 := User{Name : "wjk", Age : 23}
	//user2 := User{Name : "wjk1", Age : 24}
	//db.Create(&user1)
	//db.Create(&user2)

	//判断创建的主键是否为空,blank true, false
	//b := db.NewRecord(user1)
	//fmt.Println(b)

	//获取第一条记录
	//var user User
	//db.First(&user)
	//fmt.Println(user)

	//获取列表
	//var users []User
	//db.Find(&users)
	//fmt.Println(users)

	//where 条件
	//var user User
	//db.Where("id = ?", 2).Find(&user)
	//fmt.Println(user)

	//update
	//var user User
	//db.First(&user)
	//db.Model(&user).Update("age", 100)

	//delete
	//var user User
	//db.Where("id = ?", 3).First(&user)
	//db.Where("id = ?", 3).Delete(&user)
}
