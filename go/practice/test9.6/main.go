package main

import (
	"image/png"
	"os"
	"runtime"
)

func main() {
	workers := runtime.GOMAXPROCS(-1)
	img := ConCurrentRender(workers)
	png.Encode(os.Stdout, img)
}
