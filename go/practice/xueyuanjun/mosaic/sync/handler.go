//用户上传图片马赛克处理
package sync

import (
	"bytes"
	"encoding/base64"
	"fmt"
	"html/template"
	"image"
	"image/draw"
	"image/jpeg"
	"mosaic/common"
	"net/http"
	"os"
	"strconv"
	"time"
)

//马赛克结果页面
func Mosaic(w http.ResponseWriter, r *http.Request) {
	t0 := time.Now()
	//POST表单,最大上传大小
	r.ParseMultipartForm(10485760)//10M
	//读取 image字段
	file, _, _ := r.FormFile("image")
	defer file.Close()

	//读取设置的尺寸值
	tileSize, _ := strconv.Atoi(r.FormValue("tile_size"))
	//tileSize := 320

	//解码获取原始图片
	original, _, _ := image.Decode(file)
	bounds := original.Bounds()
	//克隆目标图片用于绘制马赛克
	newimage := image.NewNRGBA(image.Rect(bounds.Min.X, bounds.Min.X, bounds.Max.X, bounds.Max.Y))
	//克隆嵌入图片数据库
	db := common.CloneTilesDB()
	//从0 0 将目标图片分成tiles_size小区块
	sp := image.Point{0, 0}
	for y := bounds.Min.Y; y < bounds.Max.Y; y = y + tileSize {
		for x := bounds.Min.X; x < bounds.Max.X; x = x + tileSize {
			r, g, b, _ := original.At(x,y).RGBA()
			color := [3]float64{float64(r), float64(g), float64(b)}
			//从嵌入图片数据库获取平均颜色与之最接近的嵌入图片
			nearest := db.Nearest(color)
			if nearest == "" {
				nearest = "tiles/test.jpeg"
			}
			file, err := os.Open(nearest)
			if err == nil {
				img, _, err := image.Decode(file)
				if err == nil {
					//将嵌入图片调整到当前区块大小
					t := common.Resize(img, tileSize)
					tile := t.SubImage(t.Bounds())
					tileBounds := image.Rect(x, y, x + tileSize, y + tileSize)
					//将调整大小后的嵌入图片绘制到当前区块位置
					draw.Draw(newimage, tileBounds, tile, sp, draw.Src)
				} else {
					fmt.Println("error Mosaic1 : ", err, nearest)
				}
			} else {
				fmt.Println("error Mosaic2 : ", err, nearest)
				fmt.Println(nearest)
			}
			file.Close()
		}
	}

	buf1 := new(bytes.Buffer)
	jpeg.Encode(buf1, original, nil)
	//原始图片base64
	originalStr := base64.StdEncoding.EncodeToString(buf1.Bytes())

	buf2 := new(bytes.Buffer)
	jpeg.Encode(buf2, newimage, nil)
	//马赛克图片的base64
	mosaic := base64.StdEncoding.EncodeToString(buf2.Bytes())

	t1 := time.Now()
	images := map[string]string{
		"original":originalStr,
		"mosaic":mosaic,
		"duration" : fmt.Sprintf("%v", t1.Sub(t0)),
	}

	//将images渲染到HTML返回
	t, _ := template.ParseFiles("views/results.html")
	t.Execute(w, images)
}

//上传页面
func Upload(w http.ResponseWriter, r *http.Request) {
	t, _ := template.ParseFiles("views/upload.html")
	t.Execute(w, nil)
}