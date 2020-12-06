package mysql

type Post struct {
	Id int
	Title string
	Content string
	Author string
	Comments []Comment
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
	//获取关联的comments
	rows, err := Db.Query("select id, content, author from comments where post_id = ?", post.Id)
	if err != nil {
		panic(err)
	}
	defer rows.Close()
	for rows.Next() {
		comment := Comment{Post:&post}
		err = rows.Scan(&comment.Id, &comment.Content, &comment.Author)
		if err != nil {
			panic(err)
		}
		post.Comments = append(post.Comments, comment)
	}

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