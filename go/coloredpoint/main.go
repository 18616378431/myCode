package main

import (
	"fmt"
	"gopl.io/ch6/geometry"
	"image/color"
)

type ColoredPoint struct {
	geometry.Point
	Color color.RGBA
}

type ColoredPoint1 struct {
	*geometry.Point
	Color color.RGBA
}

func main() {
	var cp ColoredPoint
	cp.X = 1
	fmt.Println(cp.Point.X)
	cp.Point.Y = 2
	fmt.Println(cp.Y)

	red := color.RGBA{255, 0, 0, 255}
	blue := color.RGBA{0, 0, 255, 255}
	var p = ColoredPoint{geometry.Point{1, 1}, red}
	var q = ColoredPoint{geometry.Point{5, 4}, blue}
	fmt.Println(p.Distance(q.Point))
	p.ScaleBy(2)
	q.ScaleBy(2)
	fmt.Println(p.Distance(q.Point))

	var p1 = ColoredPoint1{&geometry.Point{1, 1}, red}
	var q1 = ColoredPoint1{&geometry.Point{5, 4}, blue}
	fmt.Println(p1.Distance(*q1.Point))
	q1.Point = p1.Point
	p1.ScaleBy(2)
	fmt.Println(*p1.Point, *q1.Point)
}
