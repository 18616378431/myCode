//队列接口
#ifndef QUEUE_H_
#define QUEUE_H_

#define BOOL int
#define TRUE 1
#define FALSE 0

#define MAXQUEUE 10
#define NAMESIZE 20

typedef struct item{		//项目信息
	char petname[NAMESIZE];
	char petkind[NAMESIZE];
}Item;

typedef struct qnode{
	Item item;
	struct qnode * next;
}Qnode;

typedef struct queue{
	Qnode * head;//指向列表头
	Qnode * end;//指向列表尾
	int items;//列表中项目的数量
}Queue;

void print1();
//函数原型
/*
操作:初始化队列
操作前:pq指向一个队列
操作后:将队列初始化为空队列
*/
Queue * InitializeQueue();

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
BOOL DeQueue(Item *pItem,Queue * pq);

/*
操作:清空队列
操作前:pq指向已初始化的队列
操作后:队列被清空
*/
void EmptyQueue(Queue * pq);

/*
操作:将函数作用于队列中的每一项
操作前:pq指向已初始化的队列，pfun指向一个函数
操作后:将pfun指向的函数作用于队列中的每一项
*/
BOOL TraverseQueue(const Queue * pq,void (*pfun)(Item item));
#endif