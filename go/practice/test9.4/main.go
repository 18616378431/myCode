package main

func pipline(stages int) (chan <- interface{}, <- chan interface{}) {
	if stages < 1 {
		return nil, nil
	}

	in := make(chan interface{})
	out := in

	for i := 0; i < stages; i++ {
		prev := out
		next := make(chan interface{})
		go func() {
			for v := range prev {
				next <- v
			}
			close(next)
		}()
		out = next
	}
	return in, out
}