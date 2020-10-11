package main

import (
	"fmt"
	"io"
	"log"
	"math"
	"net/http"
)

const (
	width, height = 600, 320 	//画布宽高
	cells = 100					//单元格数量
	xyrange = 30.0				//坐标轴范围
	xyscale = width / 2 / xyrange//单位长度像素
	zscale = height * 0.4		//z轴单位长度像素
	angle = math.Pi / 6			//x、y轴角度
)

var sin30, cos30 = math.Sin(angle), math.Cos(angle)

func main() {
	handler := func(w http.ResponseWriter, r * http.Request) {
		w.Header().Set("Content-Type", "image/svg+xml")
		image(w)
	}
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe(":8080", nil))
}

func image(out io.Writer) {
	fmt.Fprintf(out, "<svg xmlns='http://www.w3.org/2000/svg' " +
		"style='stroke:grey;fill:white;stroke-width:0.7' " +
		"width='%d' height='%d'>", width, height)

	min, max := getMinMax()
	for i := 0; i < cells; i++ {
		for j := 0; j < cells; j++ {
			ax, ay, r, g, b := corner(i + 1, j, min, max)
			bx, by, r, g, b := corner(i, j, min, max)
			cx, cy, r, g, b := corner(i, j + 1, min, max)
			dx, dy, r, g, b := corner(i + 1, j + 1, min, max)
			fmt.Fprintf(out, "<polygon points='%g,%g %g,%g %g,%g %g,%g' fill='#%x%x%x' />\n",
				ax, ay, bx, by, cx, cy, dx, dy, r, g ,b)
		}
	}
	fmt.Fprintf(out, "</svg>")
}

func corner(i, j int, min, max float64) (float64, float64, int, int, int) {
	x := xyrange * (float64(i) / cells - 0.5)
	y := xyrange * (float64(j) / cells - 0.5)
	z := f(x, y)
	sx := width / 2 + (x - y) * cos30 * xyscale
	sy := height / 2 + (x + y) * sin30 * xyscale - z * zscale
	r, g, b := getColor(min, max, z)
	return sx, sy, r, g, b
}

func f(x, y float64) float64 {
	r := math.Hypot(x, y)
	return math.Sin(r) / r
}

func getMinMax() (float64, float64) {
	var min, max float64
	for i := 0; i < cells; i++ {
		for j := 0; j < cells; j++ {
			x := xyrange * (float64(i) / cells - 0.5)
			y := xyrange * (float64(j) / cells - 0.5)
			z := f(x, y)
			if z < min {
				min = z
			}
			if z > max {
				max = z
			}
		}
	}
	return min, max
}

func getColor(min, max, current float64) (int, int, int) {
	step := (max - min) / 255
	v := int((current - min) / step)
	r := v
	g := 0
	b := 255 - v
	return r, g, b
}