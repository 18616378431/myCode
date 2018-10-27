//5.
#include<iostream>
#include"Stack.h"

Stack::Stack()
{
	top = 0;
	total = 0;
}
bool Stack::isempty()const
{
	return top == 0;
}
bool Stack::isfull()const
{
	return top == MAX;
}
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
bool Stack::pop(Item & item)
{
	if(top > 0)
	{
		item = items[--top];
		total += item.payment;
		std::cout << "Total is " << total << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}