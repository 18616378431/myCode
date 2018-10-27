#include <iostream>
#include"stack.h"

//���캯��
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
//��������
Stack::~Stack()
{
	delete [] pitems;
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
		pitems[top++] = item;
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
		item = pitems[--top];
		return true;
	}
	else
	{
		return false;
	}
}
//���ظ�ֵ������ =
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