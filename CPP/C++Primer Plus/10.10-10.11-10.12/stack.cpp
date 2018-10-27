#include"stack.h"

//构造函数
Stack::Stack()
{
	top = 0;
}
//判栈空
bool Stack::isempty()const
{
	return top == 0;
}
//判栈满
bool Stack::isfull()const
{
	return top == MAX;
}
//压入
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
//弹出
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