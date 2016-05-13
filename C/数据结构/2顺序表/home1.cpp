#include<iostream>
#include<string.h>
#include"home1.h"

using namespace std;

//构造空表
void InitalizeSeq(int * seqLen)
{
	*seqLen = 0;
}
//是否已满
bool SeqIsFull(int * seqLen)
{
	return *seqLen == MAXSIZE ? true : false;
}
//是否为空
bool SeqIsEmpty(int * seqLen)
{
	return *seqLen == NULL ? true : false;
}
//尾插法插入元素
bool AddItem(Item * pSeq, int * seqLen, const Item * temp)
{
	if (SeqIsFull(seqLen))
	{
		fprintf(stderr,"List is full!\n");
		return false;
	}
	if (SeqIsEmpty(seqLen))
	{
		pSeq[0] = *temp;
	}
	else
	{
		pSeq[*seqLen] = *temp;
	}
	(*seqLen)++;
	return true;
}
//查找指定元素
bool SeekItem(Item * pSeq, int * seqLen, Item temp)
{
	int index = 0;//遍历顺序表索引

	if (SeqIsEmpty(seqLen))
	{
		fprintf(stderr,"List is empty!\n");
		return false;
	}
	while (index < *seqLen)
	{
		if (pSeq[index].stuId == temp.stuId && (strcmp(pSeq[index].name, temp.name) == 0))
		{
			break;
		}
		index++;
	}
	if (index == *seqLen)
	{
		return false;
	}
	return true;
}
//删除指定元素i
bool DeleteItem(Item * pSeq, int * seqLen, int i)
{
	int index;

	if (i > *seqLen || i < 0)
	{
		fprintf(stderr,"Error value of \"i\",Please try again!\n");
		return false;
	}
	for (index = i - 1; index < *seqLen; index++)
	{
		pSeq[index] = pSeq[index + 1];
	}
	(*seqLen)--;
	return true;
}
//清空顺序表
void EmptyList(int * seqLen)
{
	*seqLen = 0;
}
//将指定函数作用于顺序表
void Traverse(Item * pSeq,int * seqLen,void (*pfun)(Item item))
{
	int index = 0;
	
	if(SeqIsEmpty(seqLen))
	{
		cout << "Empty list!" << endl;
		return ;
	}
	while (index < *seqLen)
	{
		(*pfun)(pSeq[index++]);
	}
}