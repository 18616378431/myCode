#ifndef QUEUE_H_
#define QUEUE_H_

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct item{
	long arrive;//顾客到达时间
	int preocesstime;//咨询时间
}Item;

#define MAXQUEUE 10

typedef struct node{
	Item item;
	struct node * next;
}Node;

typedef struct queue{
	Node * head;//头指针
	Node * end;//尾指针
	int items;//队列中项目数量
}Queue;

/*
操作:初始化队列
操作前:pq指向一个队列
操作后:将队列初始化为空队列
*/
void InitializeQueue(Queue * pq);

/*
操作:确定队列是否为空
操作前:pq指向已初始化的队列
操作后:空，返回true，否则返回false
*/
BOOL QueueIsEmpty(const Queue * pq);

/*
操作:确定队列是否已满
操作前:pq指向已初始化的队列
操作后:满，返回true，否则返回false
*/
BOOL QueueIsFull(const Queue * pq);

/*
操作:确定队列中项目的个数
操作前:pq指向已初始化的队列
操作后:返回队列中项目的个数
*/
int QueueItemCount(const Queue * pq);

/*
操作:向队列尾端添加项目
操作前:pq指向已初始化的队列，item为向队列尾端添加的项目
操作后:队列未满，向队列尾端添加项目，返回true，否则不添加，返回false
*/
BOOL EnQueue(Item item,Queue * pq);

/*
操作:从队列首端删除项目
操作前:pq指向已初始化的队列
操作后:	队列非空，首端的项目赋值到*pItem并删除，返回true;
		该操作使队列为空，把队列重置为空队列;
		队列开始为空，不改变队列，返回false
*/
BOOL DeQueue(Item * pItem,Queue * pq);

/*
操作:清空队列
操作前:pq指向已初始化的队列
操作后:队列被清空
*/
void EmptyQueue(Queue * pq);

void delMore();
#endif