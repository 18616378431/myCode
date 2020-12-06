package mysql

import (
	"database/sql"
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