package main

import (
	"fmt"
	"log"
	"net/http"
	"reflect"
	"regexp"
	"strconv"
)

func main() {
	http.HandleFunc("/search", search)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

func search(resp http.ResponseWriter, req *http.Request) {
	var data struct{
		Labels []string `http:"l"`
		MaxResults int	`http:"max"`
		Exact	bool 	`http:"x"`
	}
	data.MaxResults = 10//设置默认值
	if err := Unpack(req, &data); err != nil {
		http.Error(resp, err.Error(), http.StatusBadRequest)
		return
	}
	fmt.Fprintf(resp, "Search : %+v\n", data)
}

func Unpack(req *http.Request, ptr interface{}) error {
	if err := req.ParseForm(); err != nil {
		return err
	}
	//创建字段映射表,键为有效名称
	fields := make(map[string]reflect.Value)
	v := reflect.ValueOf(ptr).Elem()//结构变量
	for i := 0; i < v.NumField(); i++ {
		fieldInfo := v.Type().Field(i)//reflect.StructField
		tag := fieldInfo.Tag//reflect.StructTag
		typ := tag.Get("validate")

		fields[typ] = v.Field(i)
	}
	//对请求中的每个参数更新结构体中对应的字段
	for typ, values := range req.Form {
		f := fields[typ]
		if !f.IsValid() {
			continue//忽略不能识别的HTTP参数
		}
		for _, value := range values {
			if !valid(typ, value) {
				continue
			}
			if f.Kind() == reflect.Slice {
				elem := reflect.New(f.Type().Elem()).Elem()
				if err := populate(elem, value); err != nil {
					return fmt.Errorf("%s : %v", typ, err)
				}
				f.Set(reflect.Append(f, elem))
			} else {
				if err := populate(f, value); err != nil {
					return fmt.Errorf("%s : %v", typ, err)
				}
			}
		}
	}
	return nil
}

func valid(typ, v string) bool {
	switch typ {
	case "email":
		ok, _ := regexp.MatchString(
			`^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$`, v)
		return ok
	case "phone":
		ok, _ := regexp.MatchString(
			`^(13[0-9]|14[5|7]|15[0|1|2|3|5|6|7|8|9]|18[0|1|2|3|5|6|7|8|9])\d{8}$`, v)
		return ok
	case "zip":
		// 六位数
		i, _ := strconv.ParseInt(v, 10, 64)
		return i < 1000000
	default:
		panic(fmt.Sprintf("unsupported type: %s", typ))
	}
}

func populate(v reflect.Value, value string) error {
	switch v.Kind() {
	case reflect.String:
		v.SetString(value)
	case reflect.Int:
		i, err := strconv.ParseInt(value, 10, 64)
		if err != nil {
			return err
		}
		v.SetInt(i)
	case reflect.Bool:
		b, err := strconv.ParseBool(value)
		if err != nil {
			return err
		}
		v.SetBool(b)
	default:
		return fmt.Errorf("unsupported kind %s", v.Type())
	}
	return nil
}
