package main

import "sync"

var (
	mu sync.Mutex
	mapping = make(map[string]string)
)

//内嵌匿名结构体并声明方法
var cache = struct {
	sync.Mutex
	mapping map[string]string
} {
	mapping: make(map[string]string),
}

func main() {
	
}

func lookup(key string) string {
	mu.Lock()
	v := mapping[key]
	mu.Unlock()
	return v
}

func lookup1(key string) string {
	cache.Lock()
	v := cache.mapping[key]
	cache.Unlock()
	return v
}