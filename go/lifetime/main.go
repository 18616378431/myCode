package main

import (
	"fmt"
	"log"
	"os"
)

var cwd string

func main() {
	cwd, err := os.Getwd()
	if err != nil {
		fmt.Printf("Get wd failed, %s!", err)
	}
	log.Printf("Working directory = %s", cwd)
}
