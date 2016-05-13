#include<iostream>
#include<string.h>
#include"home1.h"

using namespace std;

//����ձ�
void InitalizeSeq(int * seqLen)
{
	*seqLen = 0;
}
//�Ƿ�����
bool SeqIsFull(int * seqLen)
{
	return *seqLen == MAXSIZE ? true : false;
}
//�Ƿ�Ϊ��
bool SeqIsEmpty(int * seqLen)
{
	return *seqLen == NULL ? true : false;
}
//β�巨����Ԫ��
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
//����ָ��Ԫ��
bool SeekItem(Item * pSeq, int * seqLen, Item temp)
{
	int index = 0;//����˳�������

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
//ɾ��ָ��Ԫ��i
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
//���˳���
void EmptyList(int * seqLen)
{
	*seqLen = 0;
}
//��ָ������������˳���
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