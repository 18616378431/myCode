package memo4

import "sync"

//函数记忆,并发非阻塞缓存

type entry struct {
	res result
	ready chan struct{}//res准备好后会关闭
}

type Memo struct {
	f Func
	mu sync.Mutex//保护cache
	cache map[string]*entry
}

//记忆的函数类型
type Func func(key string) (interface{}, error)

type result struct {
	value interface{}
	err error
}

func New(f Func) (*Memo) {
	return &Memo{f : f, cache : make(map[string]*entry)}
}

//非并发安全
func (memo *Memo) Get(key string) (value interface{}, err error) {
	memo.mu.Lock()
	e := memo.cache[key]

	if e == nil {
		e = &entry{ready : make(chan struct{})}
		memo.cache[key] = e
		memo.mu.Unlock()

		e.res.value, e.res.err = memo.f(key)

		close(e.ready)
	} else {
		memo.mu.Unlock()
		<- e.ready
	}

	return e.res.value, e.res.err
}


