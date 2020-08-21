package word

import "unicode"

//检测字符串是否是回文,忽略字母大小写,及非字母字符
func IsPalindrome(s string) bool {
	var letters []rune
	for _, r := range s {
		if unicode.IsLetter(r) {
			letters = append(letters, unicode.ToLower(r))
		}
	}
	for i := range letters {
		if letters[i] != letters[len(letters) - 1 - i] {
			return false
		}
	}
	return true
}
