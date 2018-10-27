#include"stack.h"

//���캯��
Stack::Stack()
{
	top = 0;
}
//��ջ��
bool Stack::isempty()const
{
	return top == 0;
}
//��ջ��
bool Stack::isfull()const
{
	return top == MAX;
}
//ѹ��
bool Stack::push(const Item & item)
{
	if(top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}
//����
bool Stack::pop(Item & item)
{
	if(top > 0)
	{
		item = items[--top];
		return true;
	}
	else
	{
		return false;
	}
}