package word

//测试

//检测一个字符串是否为回文
func IsPalindrome(s string) bool {
	for i := range s {
		if s[i] != s[len(s) - 1 - i] {
			return false
		}
	}
	return true
}