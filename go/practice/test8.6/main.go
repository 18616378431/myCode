package main

import (
	"flag"
	"fmt"
	"gopl.io/ch5/links"
	"log"
	"os"
)

var tokens = make(chan struct{}, 20)

type work struct {
	url string
	depth int
}

var de = flag.Int("depth", 3, "depth")

func crawl(w work) []work {
	fmt.Printf("depth : %d----url : %s\n", w.depth, w.url)
	if w.depth >= *de {
		return nil
	}
	tokens <- struct{}{}
	urls, err := links.Extract(w.url)
	<-tokens
	if err != nil {
		log.Print(err)
	}
	var works []work
	for _, url := range urls {
		works = append(works, work{url, w.depth + 1})
	}
	return works
}

func main() {
	flag.Parse()

	worklist := make(chan []work)
	var n int

	n++
	go func() {
		var works []work
		for _, url := range os.Args[2:] {
			works = append(works, work{url, 1})
		}
		worklist <- works
	}()

	seen := make(map[string]bool)
	for ; n > 0; n-- {
		works := <- worklist
		for _, w := range works {
			if !seen[w.url] {
				seen[w.url] = true
				n++
				go func(w work) {
					worklist <- crawl(w)
				}(w)
			}
		}
	}
}


