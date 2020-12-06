package main

import (
	"database/sql"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
)

var Db *sql.DB

//dsn:
//[username[:password]@][protocol[(address)]]/dbname[?param1=value1&...&paramN=valueN]
func init() {
	var err error
	Db, err = sql.Open("mysql", "root:root@tcp(localhost:3306)/test_db?charset=utf8mb4&parseTime=true")
	if err != nil {
		panic(err)
	}
}

type Post struct {
	Id int
	Title string
	Content string
	Author string
}

//insert
func (post *Post) Create() (err error) {
	sql := "insert into posts(title, content, author) values(?, ?, ?)"
	stmt, err := Db.Prepare(sql)
	if err != nil {
		panic(err)
	}
	defer stmt.Close()

	//stmt.QueryRow(post.Title, post.Content, post.Author)
	//res, err := Db.Exec(sql, post.Title, post.Content, post.Author)
	res, err := stmt.Exec(post.Title, post.Content, post.Author)
	if err != nil {
		panic(err)
	}

	postId, _ := res.LastInsertId()
	post.Id = int(postId)
	return
}

//select
func GetPost(id int) (post Post, err error) {
	post = Post{}
	err = Db.QueryRow("select id, title, content, author from posts where id = ?", id).
		Scan(&post.Id, &post.Title, &post.Content, &post.Author)

	//rows, err := Db.Query("select id, title, content, author from posts where id = ? limit 1", id)
	//if err != nil {
	//	panic(err)
	//}
	//defer rows.Close()
	//for rows.Next() {
	//	post = Post{}
	//	err = rows.Scan(&post.Id, &post.Title, &post.Content, &post.Author)
	//	if err != nil {
	//		panic(err)
	//	}
	//}
	return
}

//list
func Posts(limit int) (posts []Post, err error) {
	rows, err := Db.Query("select id, title, content, author from posts limit ?", limit)
	if err != nil {
		panic(err)
	}
	defer rows.Close()
	for rows.Next() {
		post := Post{}
		err = rows.Scan(&post.Id, &post.Title, &post.Content, &post.Author)
		if err != nil {
			panic(err)
		}
		posts = append(posts, post)
	}

	//prepare
	//stmt, err := Db.Prepare("select id, title, content, author from posts limit ?")
	//if err != nil {
	//	panic(err)
	//}
	//defer stmt.Close()
	//rows, err = stmt.Query(limit)
	//if err != nil {
	//	panic(err)
	//}
	return
}

func (post *Post) Update() (err error) {
	stmt, err := Db.Prepare("update posts set title = ?, content = ?, author = ? where id = ?")
	if err != nil {
		panic(err)
	}
	stmt.Exec(post.Title, post.Content, post.Author, post.Id)
	//Db.Exec/stmt.QueryRow
	//_, err = Db.Exec("update posts set title = ?, content = ?, author = ? where id = ?",
	//	post.Title, post.Content, post.Author, post.Id)
	return
}

func (post *Post) Delete() (err error) {
	stmt, err := Db.Prepare("delete from posts where id = ?")
	if err != nil {
		panic(err)
	}
	stmt.Exec(post.Id)
	//Db.Exec
	//_, err = Db.Exec("delete from posts where id = ?", post.Id)
	return
}


func main() {
	post := Post{
		Title:"Go语言数据库操作",
		Content:"基于第三方 go-sql-driver/mysql 包实现 MySQL 数据库增删改查",
		Author:"学院君",
	}

	//insert
	post.Create()
	fmt.Println(post)

	//get
	dbPost, _ := GetPost(post.Id)
	fmt.Println(dbPost)

	//update
	dbPost.Title = "Golang数据库操作"
	dbPost.Update()

	//list
	posts, _ := Posts(1)
	fmt.Println(posts)

	//delete
	//dbPost.Delete()
}
