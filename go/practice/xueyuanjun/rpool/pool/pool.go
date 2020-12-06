package pool

import (
	"errors"
	"io"
	"log"
	"sync"
)

type Pool struct {
	m sync.Mutex
	resources chan io.Closer
	factory func() (io.Closer, error)
	closed bool
}

var ErrPoolClosed = errors.New("资源池已关闭")

//初始化
func New(fn func() (io.Closer, error), size uint) (*Pool, error) {
	if size <= 0 {
		return nil, errors.New("资源池容量需要大于0")
	}
	return &Pool{
		factory:fn,
		resources:make(chan io.Closer, size),
	}, nil
}

//获取资源,不存在则创建,在release时将其加入到资源池
func(p *Pool) Acquire() (io.Closer, error) {
	select {
	case r, ok := <- p.resources:
		log.Println("Acquire:", "共享资源")
		if !ok {
			return nil, ErrPoolClosed
		}
		return r, nil
	default:
		log.Println("Acquire:", "新增资源")
		return p.factory()
	}
}

//释放资源到资源池或关闭
func (p *Pool)Release(r io.Closer) {
	p.m.Lock()
	defer p.m.Unlock()

	if p.closed {
		r.Close()
		return
	}

	select {
	case p.resources <- r:
		log.Println("Release:", "In Queue")
	default:
		log.Println("Release:", "Closing")
		r.Close()
	}
}

//关闭资源池
func (p *Pool) Close() {
	p.m.Lock()
	defer p.m.Unlock()

	if p.closed {
		return
	}

	close(p.resources)

	for r := range p.resources {
		r.Close()
	}
}