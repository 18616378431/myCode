//����ʵ���ļ�
#include<stdio.h>
#include<stdlib.h>
#include"8list.h"

extern int size;

static void delMore();
static void CopyToNode(const Item item,Qnode * pn);
static void CopyToItem(Qnode * pn,Item * pi);

void print1()
{
	/*size++;
	printf("size is %d.\n",++size);*/
}

Queue * InitializeQueue()
{
	Queue * new_pq;

	new_pq = (Queue *)malloc(sizeof(Queue));
	new_pq->head = new_pq->end = NULL;
	new_pq->items = 0;
	
	return new_pq;
}
BOOL QueueIsEmpty(const Queue * pq)
{
	return pq->items == 0; 
}
BOOL QueueIsFull(const Queue * pq)
{
	return pq->items == MAXQUEUE;
}
int QueueItemCount(const Queue * pq)
{
	return pq->items;
}
BOOL EnQueue(Item item,Queue * pq)
{
	Qnode * pnew;
	
	if(QueueIsFull(pq))
		return FALSE;
	pnew = (Qnode *)malloc(sizeof(Qnode));
	if(pnew == NULL)
	{
		fprintf(stderr,"Unable allocate memory!\n");
		exit(1);
	}
	CopyToNode(item,pnew);
	pnew->next = NULL;
	if(QueueIsEmpty(pq))
		pq->head = pnew;
	else
		pq->end->next = pnew;
	pq->end = pnew;
	pq->items++;
	return TRUE;
}
BOOL DeQueue(Item *pItem,Queue * pq)
{
	Qnode * pt;

	if(QueueIsEmpty(pq))
		return FALSE;
	CopyToItem(pq->head,pItem);
	pt = pq->head;//��¼ͷָ��
	pq->head = pq->head->next;//��ͷָ��ָ����һ���ڵ�
	free(pt);//�ͷż�¼ͷָ��ı���ָ����ڴ�
	pq->items--;
	if(pq->items == 0)
		pq->end = NULL;
	return TRUE;
}
void EmptyQueue(Queue * pq)
{
	Item dummy;

	while(!QueueIsEmpty(pq))
		DeQueue(&dummy,pq);
}
//�����ݹ����ĺ��������ڶ����е�ÿһ��
BOOL TraverseQueue(const Queue * pq,void (* pfun)(Item item))
{
	Qnode * pnode = pq->head;//��ȡͷָ���ֵ

	while(pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
	return TRUE;
}


//�ڲ�����
static void CopyToNode(const Item item,Qnode * pn)
{
	pn->item = item;
}
static void CopyToItem(Qnode * pn,Item * pi)
{
	*pi = pn->item;
}
static void delMore()
{
	while(getchar() != '\n')
		continue;
}