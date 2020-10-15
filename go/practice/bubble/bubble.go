package main

func main() {
	OldBubble()
	NewBubble()
	Best()
}

func OldBubble() {
	slice := []int{3, 1, 2, 5, 4}

	for i := 0; i < len(slice); i++ {
		for j := 0; j < len(slice); j++ {
			if slice[i] < slice[j] {
				temp := slice[i]
				slice[i] = slice[j]
				slice[j] = temp
			}
		}
	}

	//fmt.Println(slice)
}

func NewBubble() {
	slice := []int{3, 1, 2, 5, 4}

	for i := 0; i < len(slice) - 1; i++ {
		for j := i + 1; j < len(slice); j++ {
			if slice[i] > slice[j] {
				temp := slice[i]
				slice[i] = slice[j]
				slice[j] = temp
			}
		}
	}

	//fmt.Println(slice)
}

func Best() {
	//slice := []int{3, 1, 2, 5, 4}
	slice := []int{ 5, 4, 3, 2, 1}

	for i, flag := len(slice) - 1, true; i > 0; i, flag = i - 1, true {
		for j := 0; j < i; j++ {
			if slice[j] > slice[j + 1] {
				temp := slice[j]
				slice[j] = slice[j + 1]
				slice[j + 1] = temp
				flag = false
			}
		}

		if flag {
			break
		}
	}

	//fmt.Println(slice)
}