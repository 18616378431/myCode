////栈实现文件
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include"5stack.h"
//
////初始化栈
//void InitalizeStack(Stack * ps)
//{
//	ps->top = 0;
//}
////确定栈是否为空
//BOOL StackIsEmpty(const Stack * ps)
//{
//	if(ps->top == 0)
//		return true;
//	else
//		return false;
//}
////确定栈是否已满
//BOOL StackIsFull(const Stack * ps)
//{
//	BOOL flag;
//
//	if(ps->top == MAX)
//		flag = true;
//	else
//		flag = false;
//	return flag;
//}
////向栈顶添加项目
//BOOL Push(Item * item,Stack * ps)
//{
//	if(StackIsFull(ps))
//		return false;
//	strcpy(ps->item,item);//将新项目添加到节点中
//	if(StackIsEmpty(ps))
//	{
//		strcpy(ps->item,item);
//		ps->top += (int)strlen(item);
//	}
//	else
//	{
//		if((strlen(ps->item) + strlen(item)) > MAX)
//		{
//			strncat(ps->item,item,(MAX - strlen(ps->item)));
//		}
//		else
//		{
//			strcat(ps->item,item);
//		}
//		ps->top += (int)strlen(item);
//	}
//	return true;
//}
////从栈顶删除项目
//BOOL Pop(Stack * ps)
//{
//	if(StackIsEmpty(ps))
//		return false;
//	ps->top--;
//	return true;
//}
////清空栈
//void EmptyStack(Stack * ps)
//{
//	while(!StackIsEmpty(ps))
//		Pop(ps);
//}