package main

import (
	"bytes"
	"fmt"
	"io"
	"sync"
	"time"
)

type DataBucket struct {
	buffer *bytes.Buffer//缓冲区
	mutex *sync.RWMutex//读写锁
	cond *sync.Cond//条件变量
}

func NewDataBucket() *DataBucket {
	buf := make([]byte, 0)
	db := &DataBucket{
		buffer:bytes.NewBuffer(buf),
		mutex:new(sync.RWMutex),
	}
	db.cond = sync.NewCond(db.mutex.RLocker())
	return db
}

//read
func (db *DataBucket) Read(i int) {
	db.mutex.RLock()
	defer db.mutex.RUnlock()
	var data []byte
	var d byte
	var err error
	for {
		//每次读取一个字节
		if d, err = db.buffer.ReadByte(); err != nil {
			if err == io.EOF {
				if string(data) != "" {
					fmt.Printf("reader-%d:%s\n", i, data)
				}
				db.cond.Wait()//缓冲区为空,wait等待,阻塞
				data = data[:0]
				continue
			}
		}
		data = append(data, d)
	}
}

//write
func (db *DataBucket) Put(d []byte) (int, error) {
	db.mutex.Lock()
	defer db.mutex.Unlock()
	n, err := db.buffer.Write(d)
	//db.cond.Signal()//写入数据后通过signal通知处于阻塞状态的读取器
	db.cond.Broadcast()//写入数据后通过signal通知处于阻塞状态的读取器
	return n, err
}

func main() {
	db := NewDataBucket()

	for i := 1; i <= 3; i++ {
		go db.Read(i)
	}

	for j := 0; j < 10; j++ {
		go func(i int) {
			d := fmt.Sprintf("data-%d", i)
			db.Put([]byte(d))
		}(j)
		time.Sleep(100 * time.Millisecond)
	}
}
