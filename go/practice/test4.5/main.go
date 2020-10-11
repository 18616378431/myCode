package main

import "fmt"

func main() {
	str := []string{
		"abcddefggh",
		"abcddefggh",
		"abcddefggh",
		"xxx",
		"xxx1",
		"xxx1",
		"rrrrrr",
	}
	fmt.Println(distinct(str))
}

func distinct(s []string) []string {
	dist := s[0:1]
	for i := 1; i < len(s); i++ {
		for s[i] != dist[len(dist) - 1] {
			dist = append(dist, s[i])
		}
	}
	return dist
}