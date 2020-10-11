package main

import (
	"flag"
	"fmt"
	"gopl.io/practice/index"
)

var id = flag.Int("i", 0, "")
var title = flag.String("t", "", "title")

func main() {
	//index.BuildIndex()

	flag.Parse()
	res := index.Search(*id, *title)
	fmt.Printf("Total : %d\n", len(res))
	for _, info := range res {
		fmt.Printf("Url:%s/%d\n", index.XkcdUrl, info.Num)
		fmt.Println(info.Transcript)
	}
}
