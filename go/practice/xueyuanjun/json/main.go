package main

import (
	"encoding/json"
	"fmt"
	"log"
	"os"
)

type User struct {
	Name string
	Website string
	Age uint
	Male bool
	Skills []string
}

func main() {
	user := User{
		"学院君",
		"https://xueyuanjun.com",
		18,
		true,
		[]string{"Golang", "PHP", "C", "Java", "Python"},
	}
	u, err := json.Marshal(user)
	if err != nil {
		fmt.Printf("JSON编码失败 : %v\n", err)
		return
	}
	fmt.Printf("JSON格式数据 : %s\n", u)

	//解码
	var user2 User
	err = json.Unmarshal(u, &user2)
	if err != nil {
		fmt.Printf("JSON解码失败 : %v\n", err)
		return
	}
	fmt.Printf("JSON解码结果 : %#v\n", user2)

	//JSON字段和类型字段不对应的情况 不匹配的字段为类型0值,多余的字段会被丢弃
	u2 := []byte(`{"name": "学院君", "website": "https://xueyuanjun.com", "alias": "Laravel学院"}`)
	var user3 User
	err = json.Unmarshal(u2, &user3)
	if err != nil {
		fmt.Printf("JSON 解码失败：%v\n", err)
		return
	}
	fmt.Printf("JSON 解码结果: %#v\n", user3)

	//未知结构解码
	var user4 interface{}
	//err = json.Unmarshal(u2, &user4)
	err = json.Unmarshal(u, &user4)
	if err != nil {
		log.Fatalf("JSON解码失败:%v\n", err)
	}
	fmt.Printf("未知结构解码,JSON解码结果 : %v\n", user4)

	//访问解码后的数据
	user5, ok := user4.(map[string]interface{})
	if ok {
		for k, v := range user5 {
			switch v2 := v.(type) {
			case string:
				fmt.Println(k, " is string ", v2)
			case int:
				fmt.Println(k, " is int ", v2)
			case bool:
				fmt.Println(k, " is bool ", v2)
			case []interface{}:
				fmt.Println(k, " is an array:")
				for i, iv := range v2 {
					fmt.Println(i, iv)
				}
			default:
				fmt.Println(k, " is another type not handle yet")
			}

		}
	}

	//从标准输入读取json格式数据,将其解码
	//将解码后的数据进行编码,输出到标准输出
	//{"Name":"学院君","Website":"https://xueyuanjun.com","Age":18,"Male":true,"Skills":["Golang","PHP","C","Java","Python"]}
	dec := json.NewDecoder(os.Stdin)
	enc := json.NewEncoder(os.Stdout)
	for {
		var v map[string]interface{}
		if err := dec.Decode(&v); err != nil {
			log.Println(err)
			return
		}
		fmt.Println("decode:", v)
		if err := enc.Encode(&v); err != nil {
			log.Println(err)
		}
	}
}
