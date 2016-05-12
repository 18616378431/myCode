//队列实现文件
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
//将传递过来的函数作用于队列中的每一项
BOOL TraverseQueue(const Queue * pq,void (* pfun)(Item item))
{
	Qnode * pnode = pq->head;//获取头指针的值

	while(pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
	return TRUE;
}


//内部函数
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