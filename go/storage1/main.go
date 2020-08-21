package storage

import (
	"fmt"
	"log"
	"net/smtp"
)

//白盒测试
//白盒测试:可以对实现的特定之处提供更详细的覆盖测试
//黑盒测试:仅对导出的外部API进行测试

func bytesInUsed(usename string) int64 {
	return 0
}

const sender = "notifications@example.com"
const password = "correct"
const hostname = "smtp.example.com"

const template = "Warning:you are using %d bytes of storage,%d%% of your quota."

func CheckQuota(username string) {
	used := bytesInUsed(username)
	const quota = 1000000000
	percent := 100 * used / quota
	if percent < 90 {
		return
	}
	msg := fmt.Sprintf(template, used, percent)
	auth := smtp.PlainAuth("", username, password, hostname)
	err := smtp.SendMail(hostname + ":587", auth, sender, []string{username}, []byte(msg))
	if err != nil {
		log.Printf("smtp.SendMail(%s) failed : %s", username, err)
	}
}

