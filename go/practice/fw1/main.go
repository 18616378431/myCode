//make长度为5的slice,slice前五个值为类型0值
//[0 0 0 0 0 1 2 3]
package main

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func main() {
	s := make([]int, 5)
	s = append(s, 1, 2, 3)
	fmt.Println(s)

	temp1 := &ListNode{1, nil}
	temp2 := &ListNode{2, nil}
	temp3 := &ListNode{3, nil}
	//temp10 := &ListNode{4, nil}

	temp1.Next = temp2
	temp2.Next = temp3
	//temp3.Next = temp10

	ShowList(temp1)

	temp4 := &ListNode{2, nil}
	temp5 := &ListNode{9, nil}
	temp6 := &ListNode{4, nil}
	temp7 := &ListNode{5, nil}

	temp4.Next = temp5
	temp5.Next = temp6
	temp6.Next = temp7
	temp7.Next = nil
	ShowList(temp4)

	r := addTwoNumbers(temp1, temp4)

	fmt.Println(r)
	ShowList(r)


	//Example
	fmt.Println("====")

	t1 := &ListNode{4, nil}
	t2 := &ListNode{4, nil}
	t3 := &ListNode{6, nil}
	t4 := &ListNode{6, nil}

	t1.Next = t2
	t2.Next = t3
	t3.Next = t4

	t5 := &ListNode{3, nil}
	t6 := &ListNode{3, nil}
	t7 := &ListNode{4, nil}

	t5.Next = t6
	t6.Next = t7

	ShowList(t1)
	ShowList(t5)

	r1 := addTwoNumbers(t1, t5)
	ShowList(r1)
}

func ShowList(l *ListNode) {
	for l != nil {
		fmt.Println(l.Val)
		l = l.Next
	}
}



/**
Input1:2->4->3
Input2:4->6->4
Output:6->0->8

//Example:
4->4->6->6
3->3->4
7->7->0->7
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var head *ListNode
	var prev *ListNode
	//1.后一位是否加1操作,true+1,false non
	//2.l1t,l2t标记l1到末尾或l2到末尾
	var nextFlag, l1t, l2t bool

	if l1 == nil{
		return l2
	}

	if l2 == nil {
		return l1
	}

	for l1 != nil {
		l3 := new(ListNode)

		if head == nil {
			head = l3
		}

		if nextFlag {
			l3.Val += 1
			if l3.Val >= 10 {
				l3.Val -= 10
				nextFlag = true
			} else {
				nextFlag = false
			}
		}

		if l1.Val + l2.Val >= 10 {
			nextFlag = true
		}

		if nextFlag {
			l3.Val = l1.Val + l2.Val - 10
		} else {
			l3.Val += l1.Val + l2.Val
		}

		if prev != nil {
			prev.Next = l3
		}

		prev = l3
		l1 = l1.Next
		l2 = l2.Next

		if l1 == nil {
			l1t = true
		}

		if l2 == nil {
			l2t = true
		}

		if l1t || l2t {
			break
		}
	}

	if l1t {//l2
		for l2 != nil {
			ltemp := new(ListNode)
			prev.Next = ltemp

			if nextFlag {
				ltemp.Val = l2.Val + 1
			} else {
				ltemp.Val = l2.Val
			}
			nextFlag = false

			prev = ltemp
			l2 = l2.Next
		}
	}
	if l2t {//l1
		for l1 != nil {
			ltemp := new(ListNode)
			prev.Next = ltemp

			if nextFlag {
				ltemp.Val = l1.Val + 1
			} else {
				ltemp.Val = l1.Val
			}
			nextFlag = false

			prev = ltemp
			l1 = l1.Next
		}
	}
	return head
}
