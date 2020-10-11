package main

import (
	"database/sql"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
)

type User struct {
	id int
	name string
	age int
}

func main() {
	fmt.Println("connect mysql")

	//构建连接："用户名:密码@tcp(IP:端口)/数据库?charset=utf8"
	//path := strings.Join([]string{userName, ":", password, "@tcp(", ip, ":", port, ")/", dbName, "?charset=utf8"}, "")
	//connect
	db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1)/go_mysql")

	if err != nil {
		panic("连接数据库失败")
	} else {
		fmt.Println("连接数据库成功")
	}

	//设置数据库最大连接数
	db.SetConnMaxLifetime(100)
	//设置上数据库最大闲置连接数
	db.SetMaxIdleConns(10)

	defer db.Close()

	//query
	rows, err := db.Query("select id, name, age from t_users order by id asc")
	if err != nil {
		fmt.Printf("select failed [%s]\n", err)
	}

	var mapUser map[int]User
	mapUser = make(map[int]User)
	for rows.Next() {
		var user User
		rows.Columns()
		err := rows.Scan(&user.id, &user.name, &user.age)
		if err != nil {
			fmt.Printf("get user info error [%s]\n", err)
		}
		mapUser[user.id] = user
	}

	rows.Close()

	for id, user := range mapUser {
		fmt.Println(id, user)
	}

	//Exec
	stmt, err := db.Prepare("insert into t_users (name, age) values(?, ?)")
	if err != nil {
		panic(err)
	}

	query, err := stmt.Exec("aaa", 100)
	id, err := query.LastInsertId()
	fmt.Printf("last insert id : %d\n", id)

	//prepare update
	//stmt, err := db.Prepare("update t_users set name = 'wjk1' where id = ?")
	//res, err := stmt.Exec(1)
	//id, err := res.RowsAffected()
	//fmt.Printf("affected rows : %d\n", id)

	//Transaction
	//tx, err := db.Begin()
	//if err != nil {
	//	fmt.Println("tx failed")
	//}
	//准备sql语句
	//stmt, err := tx.Prepare("delete from t_users where id = ?")
	//if err != nil {
	//	fmt.Println("prepare fail", err)
	//	return
	//}
	//res, err := stmt.Exec(3)
	//if err != nil {
	//	fmt.Println("Exec fail")
	//	err := tx.Rollback()
	//	if err != nil {
	//		fmt.Println("rollback fail")
	//	}
	//	return
	//}
	//if err := tx.Commit(); err != nil {
	//	fmt.Println("commit fail")
	//}
	//id, err := res.RowsAffected()
	//fmt.Printf("delete affected rows : %d\n", id)

}
