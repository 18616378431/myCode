package memo5

//函数记忆,并发非阻塞缓存

type request struct {
	key string
	response chan <- result
}

type entry struct {
	res result
	ready chan struct{}//res准备好后会关闭
}

type Memo struct {
	requests chan request
}

//记忆的函数类型
type Func func(key string) (interface{}, error)

type result struct {
	value interface{}
	err error
}

func New(f Func) (*Memo) {
	memo := &Memo{requests : make(chan request)}
	go memo.server(f)
	return memo
}

//非并发安全
func (memo *Memo) Get(key string) (interface{}, error) {
	response := make(chan result)
	memo.requests <- request{key,response}
	res := <- response
	return res.value, res.err
}

func (memo *Memo) Close() {
	close(memo.requests)
}

func (memo *Memo)server(f Func) {
	cache := make(map[string]*entry)
	for req := range memo.requests {
		e := cache[req.key]
		if e == nil {
			//对这个key第一次请求
			e = &entry{ready : make(chan struct{})}
			cache[req.key] = e
			go e.call(f, req.key)//调用f(key)
		}
		go e.deliver(req.response)
	}
}

func (e *entry) call(f Func, key string) {
	//执行函数
	e.res.value, e.res.err = f(key)
	//通知数据已准备完毕
	close(e.ready)
}

func (e *entry) deliver(response chan <- result) {
	//等待数据准备完毕
	<- e.ready
	//向客户端发送结果
	response <- e.res
}



