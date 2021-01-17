package models

import (
	"chitchat/config"
	"crypto/rand"
	"crypto/sha1"
	"database/sql"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"log"
)

var Db *sql.DB

func init() {
	var err error
	//conf := config.LoadConfig()
	conf := config.ViperConfig
	driver := conf.Db.Driver
	source := fmt.Sprintf("%s:%s@(%s)/%s?charset=utf8mb4&parseTime=true",
		conf.Db.User, conf.Db.Password, conf.Db.Address, conf.Db.Database)
	//Db, err = sql.Open("mysql", "root:root@tcp(localhost:3306)/go_chitchat?charset=utf8mb4&parseTime=true")
	Db, err = sql.Open(driver, source)
	if err != nil {
		log.Fatal(err)
	}
	return
}

//create a random UUID
func createUUID() (uuid string) {
	u := new([16]byte)
	_, err := rand.Read(u[:])
	if err != nil {
		log.Fatalln("Cannot generate UUID", err)
	}
	//0x40
	u[8] = (u[8] | 0x40) & 0x7F
	u[6] = (u[6] & 0xF) | (0x4 << 4)
	uuid = fmt.Sprintf("%x-%x-%x-%x-%x", u[0:4], u[4:6], u[6:8], u[8:10], u[10:])
	return
}

//hash
func Encrypt(plaintext string) (cryptext string) {
	cryptext = fmt.Sprintf("%x", sha1.Sum([]byte(plaintext)))
	return
}

