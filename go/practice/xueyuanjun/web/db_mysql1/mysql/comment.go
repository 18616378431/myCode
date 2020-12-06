package mysql

import "errors"

type Comment struct {
	Id int
	Content string
	Author string
	Post *Post
}

func (comment *Comment) Create() (err error) {
	if comment.Post == nil {
		err = errors.New("Post Not Found")
		return
	}
	sql := "insert into comments(content, author, post_id) values(?, ?, ?)"
	res, err := Db.Exec(sql, comment.Content, comment.Author, comment.Post.Id)
	if err != nil {
		panic(err)
	}

	commentId, _ := res.LastInsertId()
	comment.Id = int(commentId)
	return
}