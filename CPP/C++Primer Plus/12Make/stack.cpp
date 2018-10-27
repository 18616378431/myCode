#include <iostream>
#include"stack.h"

//构造函数
Stack::Stack()
{
	pitems = new Item[MAX];
	top = 0;
}
//copy constructor
Stack::Stack(const Stack & s)
{
	pitems = new Item[MAX];
	memcpy(pitems,s.pitems,sizeof(int) * MAX);
	top = s.top;
}
//析构函数
Stack::~Stack()
{
	delete [] pitems;
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
		pitems[top++] = item;
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
		item = pitems[--top];
		return true;
	}
	else
	{
		return false;
	}
}
//重载赋值操作符 =
Stack & Stack::operator= (const Stack & s)
{
	memcpy(pitems,s.pitems,sizeof(int) * MAX);
	top = s.top;
	return *this;
}
//show
void Stack::showContent()
{
	int temptop = top;
	while(temptop > 0)
	{
		std::cout << pitems[temptop - 1] << std::endl;
		temptop--;
	}
}