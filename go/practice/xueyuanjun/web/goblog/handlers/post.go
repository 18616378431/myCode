package handlers

import (
	"encoding/json"
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"os"
	"strings"
)

func GeoPosts(w http.ResponseWriter, r *http.Request) {
	io.WriteString(w, "All posts")
}

type Post struct {
	Title string `json:"title"`
	Content string `json:"content"`
}

//读取POST请求实体并返回
//请求实体和响应实体都通过 Body 字段表示，该字段是 io.ReadCloser 接口类型。顾名思义，这个类型实现了 io.Reader 和 io.Closer 接口。
func AddPost(w http.ResponseWriter, r *http.Request) {
	//len := r.ContentLength
	//body := make([]byte, len)
	//r.Body.Read(body)
	//io.WriteString(w, string(body))

	//根据请求实体获取json数据
	//curl -X POST -id '{"title":"test","content":"hello"}' http://localhost:8080/post/add -H "Content-Type:application/json"
	len := r.ContentLength//请求实体长度
	body := make([]byte, len)
	r.Body.Read(body)

	post := Post{}
	json.Unmarshal(body, &post)
	fmt.Fprintf(w, "%#v\n", post)
}

//测试表单数据获取
func EditPost(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()//解析表单数据
	//fmt.Fprintln(w, r.Form)//r.Form 是一个包含所有请求数据的字典类型（map）
	//id := r.Form.Get("id")
	//fmt.Println("post id : ", id)
	//fmt.Println("form data : ", r.PostForm)
	//fmt.Println("title : ", r.PostForm.Get("title"), ", content : ", r.PostForm.Get("content"))

	//还可以通过 FormValue 和 PostFormValue 获取用户请求数据
	//不再需要单独调用 ParseForm 对表单数据进行解析，不过使用这两个方法的时候只能获取特定请求数据，不能一次获取所有请求数据
	//FormValue/PostFormValue 之所以不用显式调用 ParseForm 解析请求数据，是因为底层对其进行了封装，实际上还是要调用这个方法。
	//fmt.Println("post id : ", r.FormValue("id"))
	//fmt.Println("post title : ", r.PostFormValue("title"))
	//fmt.Println("post content : ", r.PostFormValue("content"))

	//文件上传
	r.ParseMultipartForm(1024)
	fmt.Println("post file : ", r.MultipartForm)

	io.WriteString(w, "表单提交成功")
}

//http://localhost:8080/image/upload
//和 FormValue 和 PostFormValue 类似，还有一个 FormFile 用于快速获取上传文件
//默认的内存最大值是 32 MB
func UploadImage(w http.ResponseWriter, r *http.Request) {
	r.ParseMultipartForm(1024 * 1024)
	name := r.MultipartForm.Value["name"][0]//文件名
	//image := r.MultipartForm.File["image"][0]//图片文件
	image := r.MultipartForm.File["image"][1]//图片文件

	fmt.Println("图片上传成功:", name)

	file, err := image.Open()
	//file, _, err := r.FormFile("image")
	if err == nil {
		data, err := ioutil.ReadAll(file)
		if err == nil {
			//fmt.Fprintln(w, string(data))
			//将上传文件名存储到images目录下并读取文件名和后缀
			names := strings.Split(image.Filename, ".")
			suffix := names[len(names) - 1]
			filename := name + "." + suffix
			//创建文件
			newFile, _ := os.Create("images/" + filename)
			defer newFile.Close()
			//将上传的二进制字节信息写入新建的文件
			size, err := newFile.Write(data)
			if err == nil {
				fmt.Fprintf(w, "图片上传成功, 图片大小 : %d 字节\n", size / 1000)
			}
		}
	}
	if err != nil {
		fmt.Fprintln(w, err)
	}
}
