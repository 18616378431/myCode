////输入一个字符串，将每一个字符压入栈，然后弹出栈，逆序显示
//#include<stdio.h>
//#include<stdlib.h>
//#include"5stack.h"
//
//void showStack(Stack * ps);
//
//int main()
//{
//	Item temp[MAX];
//	Stack * ps = (Stack *)malloc(sizeof(Stack));
//
//	
//	InitalizeStack(ps);
//	if(StackIsFull(ps))
//	{
//		fprintf(stderr,"Stack is full!\n");
//		exit(1);
//	}
//	puts("Enter a string:");
//	gets(temp);
//	Push(temp,ps);
//	showStack(ps);
//	return 0;
//}
////showStack
//void showStack(Stack * ps)
//{
//	while(ps->top > 0)
//	{
//		putchar(ps->item[(ps->top--) - 1]);
//	}
//	putchar('\n');
//}