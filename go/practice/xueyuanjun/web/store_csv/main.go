package main

import (
	"encoding/csv"
	"fmt"
	"os"
	"strconv"
)

type Tutorial struct {
	Id int
	Title string
	Summary string
	Author string
}

func main() {
	csvFile, err := os.Create("tutorial.csv")
	if err != nil {
		panic(err)
	}
	defer csvFile.Close()

	//初始化文章信息
	tutorials := []Tutorial{
		Tutorial{Id:1, Title:"PHP全栈工程师指南", Summary:"基于Laravel+Vue.js开发Web项目", Author:"学院君"},
		Tutorial{Id:2, Title:"Go入门教程", Summary:"Go语言基础语法和使用指南", Author:"学院君"},
		Tutorial{Id:3, Title:"Go Web编程", Summary:"基于Gin框架构建Web项目", Author:"学院君"},
		Tutorial{Id:4, Title:"微服务从入门到实战", Summary:"基于Laravel+go-micro框架构建微服务", Author:"学院君"},
	}

	//在 Windows 中，可以通过 Excel 软件打开这个文件，但是现在看到的是乱码数据：
	//这是因为 Excel 默认并不是 UTF-8 编码，因此要解决这个乱码问题，
	//可以在对应的 CSV 文件写入 UTF-8 BOM 头，告知 Excel 通过 UTF-8 编码打开这个文件
	// 写入 UTF-8 BOM，防止中文乱码
	//csvFile.WriteString("\xEF\xBB\xBF")

	//初始化csvwriter 并写入到文件
	writer := csv.NewWriter(csvFile)
	for _, tutorial := range tutorials {
		line := []string{
			strconv.Itoa(tutorial.Id),
			tutorial.Title,
			tutorial.Summary,
			tutorial.Author,
		}
		//将切片类型数据写入到csv文件
		err := writer.Write(line)
		if err != nil {
			panic(err)
		}
	}
	//将缓冲区中的数据都flush到文件
	writer.Flush()

	//打开csv文件
	file, err := os.Open("tutorial.csv")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	//初始化csv reader并读取
	csvReader := csv.NewReader(file)
	//每行记录期望的字段,-1所有字段
	csvReader.FieldsPerRecord = -1
	//返回所有csv文件内容
	recoder, err := csvReader.ReadAll()
	if err != nil {
		panic(err)
	}

	var tutorials2 []Tutorial
	for _, item := range recoder {
		id, _ := strconv.Atoi(item[0])
		tutorial := Tutorial{Id:int(id), Title:item[1], Summary:item[2], Author:item[3]}
		tutorials2 = append(tutorials2, tutorial)
	}

	fmt.Println(tutorials2[0].Id)
	fmt.Println(tutorials2[0].Title)
	fmt.Println(tutorials2[0].Summary)
	fmt.Println(tutorials2[0].Author)
}
