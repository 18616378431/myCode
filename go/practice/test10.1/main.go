package main

import (
	"flag"
	"fmt"
	"image"
	"image/gif"
	"image/jpeg"
	"image/png"
	"log"
	"os"
)

var format = flag.String("format", "jpeg", "")

func main() {
	flag.Parse()
	img, kind , err := image.Decode(os.Stdin)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Fprintf(os.Stderr, "Input format = %v\n", kind)

	switch *format {
	case "jpeg":
		err := jpeg.Encode(os.Stdout, img, &jpeg.Options{Quality:100})
		if err != nil {
			log.Fatal(err)
		}
	case "png":
		err := png.Encode(os.Stdout, img)
		if err != nil {
			log.Fatal(err)
		}
	case "gif":
		err := gif.Encode(os.Stdout, img, &gif.Options{})
		if err != nil {
			log.Fatal(err)
		}
	}
}
