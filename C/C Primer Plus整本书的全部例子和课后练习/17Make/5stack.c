////ջʵ���ļ�
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include"5stack.h"
//
////��ʼ��ջ
//void InitalizeStack(Stack * ps)
//{
//	ps->top = 0;
//}
////ȷ��ջ�Ƿ�Ϊ��
//BOOL StackIsEmpty(const Stack * ps)
//{
//	if(ps->top == 0)
//		return true;
//	else
//		return false;
//}
////ȷ��ջ�Ƿ�����
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
////��ջ�������Ŀ
//BOOL Push(Item * item,Stack * ps)
//{
//	if(StackIsFull(ps))
//		return false;
//	strcpy(ps->item,item);//������Ŀ��ӵ��ڵ���
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
////��ջ��ɾ����Ŀ
//BOOL Pop(Stack * ps)
//{
//	if(StackIsEmpty(ps))
//		return false;
//	ps->top--;
//	return true;
//}
////���ջ
//void EmptyStack(Stack * ps)
//{
//	while(!StackIsEmpty(ps))
//		Pop(ps);
//}