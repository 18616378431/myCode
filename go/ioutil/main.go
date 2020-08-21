package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"sync"
)

var mu sync.Mutex
var m = make(map[string]int)

func main() {
	m["a"] = 1
	m["b"] = 2
	m["c"] = 3
	m["d"] = 4
	m["e"] = 5

	fmt.Println(ReadFile("./test.txt"))
	fmt.Println(lookup("d"))
}

func ReadFile(filename string) ([]byte, error) {
	f, err := os.Open(filename)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	return ioutil.ReadAll(f)
}

func lookup(key string) int {
	mu.Lock()
	defer mu.Unlock()
	return m[key]
}
