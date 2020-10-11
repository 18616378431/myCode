package main

import (
	"fmt"
	carbon2 "gitee.com/go-package/carbon"
)

func main() {
	carbon := carbon2.New()

	//设置时区
	carbon.Timezone(carbon2.PRC)

	fmt.Println(carbon.Now().Format("Y-m-d H:i:s"))
	fmt.Println(carbon.Now().ToDateTimeString())
	fmt.Println(carbon.Now().ToDateString())
	fmt.Println(carbon.Now().ToTimeString())

	//时间戳
	fmt.Println(carbon.Now().ToTimestamp())

	fmt.Println(carbon.Yesterday())
	fmt.Println(carbon.Today())
	fmt.Println(carbon.Tomorrow())

	//一年后
	fmt.Println(carbon.Now().AddYear().ToDateTimeString())
	//一年前
	fmt.Println(carbon.Now().SubYear().ToDateTimeString())

	fmt.Println(carbon.Parse("2020-09-08 18:05:20").Format("Y年m月d日 H时i分s秒"))

	fmt.Println(carbon.Now().IsLeapYear())
	fmt.Println(carbon.Now().IsMonday())
}
