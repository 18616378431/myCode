package main

import (
	"fmt"
	"github.com/gin-gonic/gin"
	_ "github.com/go-sql-driver/mysql"
	"github.com/jinzhu/gorm"
	"net/http"
)

//curl -i -GET http://localhost:8080/
//curl -i -X GET http://localhost:8080/people/6

//curl -i -X POST http://localhost:8080/people -d '{"firstname" : "wjk", "LastName" : "kkk"}'
//curl -i -X POST http://localhost:8080/people -d '{"firstname" : "wjk1", "LastName" : "kkk1", "city" : "sh"}'
//curl -i -X POST http://localhost:8080/people -d '{"firstname" : "wjk2", "LastName" : "kkk2", "city" : "sh"}'

//curl -i -X PUT http://localhost:8080/people/3 -d '{"firstname" : "wjk4"}'
//curl -i -X DELETE http://localhost:8080/people/1

var db *gorm.DB
var err error

type Person struct {
	ID uint `json:"id"`
	FirstName string `json:"firstname"`
	LastName string `json:"lastname"`
	City string `json:"city"`
}

func main() {
	db, err = gorm.Open("mysql", "root:root@tcp(127.0.0.1:3306)/go_mysql?charset=utf8")
	if err != nil {
		fmt.Println(err)
	}
	defer db.Close()

	db.AutoMigrate(&Person{})

	r := gin.Default()

	//router
	r.GET("/", GetProjects)
	//get
	r.GET("/people/:id", GetPerson)
	//create
	r.POST("/people", CreatePerson)
	//update
	r.PUT("/people/:id", UpdatePerson)
	//delete
	r.DELETE("/people/:id", DeletePerson)

	err = r.Run(":8080")
	if err != nil {
		fmt.Printf("gin run fail, %s\n", err)
	}
}

func GetProjects(c *gin.Context) {
	var people []Person
	if err := db.Find(&people).Error; err != nil {
		c.AbortWithStatus(404)
		fmt.Printf("error : %s\n", err)
	} else {
		c.JSON(http.StatusOK, people)
	}
}

func GetPerson(c *gin.Context) {
	id := c.Params.ByName("id")
	var person Person
	if err := db.Where("id = ?", id).First(&person).Error; err != nil {
		c.AbortWithStatus(404)
		fmt.Printf("error : %s\n", err)
	} else {
		c.JSON(http.StatusOK, person)
	}
}

func CreatePerson(c *gin.Context) {
	var person Person
	err := c.BindJSON(&person)
	if err != nil {
		fmt.Println(err)
	}
	db.Create(&person)
	c.JSON(http.StatusOK, person)
}

func UpdatePerson(c *gin.Context) {
	var person Person
	id := c.Params.ByName("id")
	if err := db.Where("id = ?", id).First(&person).Error; err != nil {
		c.AbortWithStatus(404)
		fmt.Println(err)
	}
	err = c.BindJSON(&person)
	if err != nil {
		fmt.Println(err)
	}
	db.Save(&person)
	c.JSON(http.StatusOK, person)
}

func DeletePerson(c *gin.Context) {
	id := c.Params.ByName("id")
	var person Person
	db.Where("id = ?", id).Delete(&person)
	c.JSON(http.StatusOK, gin.H{
		"id #" + id : "deleted",
	})
}
