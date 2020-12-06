//读写锁,信号量
package main

import (
	"bytes"
	"fmt"
	"io"
	"runtime"
	"sync"
	"time"
)

type DataBucket struct {
	buffer *bytes.Buffer
	mutex *sync.RWMutex
	cond *sync.Cond
}

func NewDataBucket() *DataBucket {
	buf := make([]byte, 0)
	db := &DataBucket{
		buffer : bytes.NewBuffer(buf),
		mutex : new(sync.RWMutex),
	}
	db.cond = sync.NewCond(db.mutex.RLocker())
	return db
}

//读取器
func (db *DataBucket) Read(i int) {
	db.mutex.RLock()
	defer db.mutex.RUnlock()
	var data []byte
	//var d byte
	//var err error
	for {
		//读取一个字节
		d, err := db.buffer.ReadByte()
		if err != nil {
			if err == io.EOF {//缓冲区为空时
				if string(data) != "" {//data不为空 打印
					fmt.Printf("reader-%d : %s\n", i, data)
				}
				db.cond.Wait()//等待通知,进入阻塞状态
				data = data[:0]//清空data
				continue
			}
		}
		data = append(data, d)
	}
}

//写入器
func (db *DataBucket) Put(d []byte) (int, error) {
	db.mutex.Lock()
	defer db.mutex.Unlock()
	n, err := db.buffer.Write(d)
	//db.cond.Signal()//通知阻塞状态的读取器
	db.cond.Broadcast()//通知阻塞状态的读取器,通知多个阻塞线程
	return n, err
}

func main() {
	db := NewDataBucket()

	for i := 1; i < 3; i++ {
		go db.Read(i)
	}

	for j := 0; j < 10; j++ {
		go func(i int) {
			d := fmt.Sprintf("data-%d", i)
			_, err := db.Put([]byte(d))
			if err != nil {
				fmt.Println(err)
			}
		}(j)
		time.Sleep(100 * time.Millisecond)
	}


	/**
	最后剩余3个协程,两个读线程一直阻塞在wait
	一个主协程
	 */
	fmt.Println(runtime.NumGoroutine())
	time.Sleep(1 * time.Second)
}
