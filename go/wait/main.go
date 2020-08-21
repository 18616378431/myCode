package main

import (
	"fmt"
	"log"
	"net/http"
	"time"
)

func main() {
	if err := WaitForServer("https://www.baidu.com"); err != nil {
		//fmt.Fprintf(os.Stderr, "Site is down : %v\n", err)
		//os.Exit(1)
		log.Fatalf("Site is down : %v\n", err)
	}
}

func WaitForServer(url string) error {
	const timeout = 1 * time.Minute
	deadline := time.Now().Add(timeout)
	for tries := 0; time.Now().Before(deadline); tries++ {
		_, err := http.Head(url)
		if err == nil {
			return nil
		}
		log.Printf("server not responding (%s);retrying...", err)
		time.Sleep(time.Second << uint(tries))//指数退避策略
	}
	return fmt.Errorf("server %s failed to respond after %s", url, timeout)
}
