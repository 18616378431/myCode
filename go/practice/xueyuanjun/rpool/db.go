package main

import (
	"io"
	"log"
	"math/rand"
	"rpool/pool"
	"sync"
	"sync/atomic"
	"time"
)

const (
	maxGoroutines = 5
	pooledResources = 2
)

type dbConnection struct {
	ID int32
}


func (dbConn *dbConnection) Close() error {
	log.Println("Close : Connection", dbConn.ID)
	return nil
}

var idCounter int32

//创建资源,factory
func createConnection() (io.Closer, error) {
	id := atomic.AddInt32(&idCounter, 1)
	log.Println("Create : New Connection", id)

	return &dbConnection{id}, nil
}

func main() {
	var wg sync.WaitGroup
	wg.Add(maxGoroutines)

	pool, err := pool.New(createConnection, pooledResources)
	if err != nil {
		log.Println(err)
	}

	for query := 0; query < maxGoroutines; query++ {
		go func(q int) {
			performQueries(q, pool)
			wg.Done()
		}(query)
	}

	wg.Wait()

	log.Println("Shutdown Program")
	pool.Close()
}

func performQueries(query int, p *pool.Pool) {
	conn, err := p.Acquire()
	if err != nil {
		log.Println(err)
		return
	}
	defer p.Release(conn)

	//模拟sql查询

	time.Sleep(time.Duration(rand.Intn(1000)) * time.Millisecond)
	log.Printf("QID[%d] CID[%d]\n", query, conn.(*dbConnection).ID)
}