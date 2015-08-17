#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

static void CopyToNode(Item item,Node * pn);
static void CopyToItem(Node * pn,Item * pi);

void InitializeQueue(Queue * pq)
{
	pq->head = pq->end = NULL;
	pq->items = 0;
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
	Node * pnew;
	if(QueueIsFull(pq))
		return FALSE;
	pnew = (Node *)malloc(sizeof(Node));
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
	Node * pt;

	if(QueueIsEmpty(pq))
		return FALSE;
	CopyToItem(pq->head,pItem);
	pt = pq->head;//记录头指针
	pq->head = pq->head->next;//将头指针指向下一个节点
	free(pt);//释放记录头指针的变量指向的内存
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
void CopyToNode(Item item,Node * pn)
{
	pn->item = item;
}
void CopyToItem(Node * pn,Item * pi)
{
	*pi = pn->item;
}
void delMore()
{
	while(getchar() != '\n')
		continue;
}