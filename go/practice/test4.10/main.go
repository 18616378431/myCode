//./issues repo:golang/go is:open json decoder
package main

import (
	"flag"
	"fmt"
	"gopl.io/ch4/github"
	"log"
	"os"
	"time"
)

var m = flag.Int("m", 0, "正数为最近m个月,负数为查询之后m个月之前的")

func main() {
	flag.Parse()

	q := os.Args[1:]

	fmt.Println(q)

	for i, v := range q {
		if v == "-m" {
			copy(q[i:], q[i + 2:])
			q = q[0:len(q) - 2]
			break
		}
	}

	if *m > 0 {
		end := time.Now()
		start := end.AddDate(0, -*m, 0)
		log.Println(start)
		log.Println(start.Format("2016-01-02 00:00:00"))
		q = append(q, "created:" + start.Format("2016-01-02") + ".." + end.Format("2020-01-01"))
	} else if *m < 0 {
		end := time.Now().AddDate(0, *m, 0)
		q = append(q, "created:<" + end.Format("2020-01-01"))
	}
	log.Println(q)

	result, err := github.SearchIssues(q)

	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%d issues:\n", result.TotalCount)

	for _, item := range result.Items {
		fmt.Printf("#%-5d %9.9s %.55s\n", item.Number, item.User.Login, item.Title)
	}
}
