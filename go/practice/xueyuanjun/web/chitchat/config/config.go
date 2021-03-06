package config

//单例配置

import (
	"encoding/json"
	"log"
	"os"
	"sync"
)

type App struct {
	Address string
	Static string
	Log string
}

type Database struct {
	Driver string
	Address string
	Database string
	User string
	Password string
}

type Configuration struct {
	App App
	Db Database
}

var conf *Configuration
var once sync.Once

func LoadConfig() *Configuration {
	once.Do(func() {
		file, err := os.Open("config.json")
		if err != nil {
			log.Fatalln("Cannot open config file", err)
		}
		decoder := json.NewDecoder(file)
		conf = &Configuration{}
		err = decoder.Decode(conf)
		if err != nil {
			log.Fatalln("Cannot get configuration from file", err)
		}
	})
	return conf
}