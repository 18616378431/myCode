//���нӿ�
#ifndef QUEUE_H_
#define QUEUE_H_

#define BOOL int
#define TRUE 1
#define FALSE 0

#define MAXQUEUE 10
#define NAMESIZE 20

typedef struct item{		//��Ŀ��Ϣ
	char petname[NAMESIZE];
	char petkind[NAMESIZE];
}Item;

typedef struct qnode{
	Item item;
	struct qnode * next;
}Qnode;

typedef struct queue{
	Qnode * head;//ָ���б�ͷ
	Qnode * end;//ָ���б�β
	int items;//�б�����Ŀ������
}Queue;

void print1();
//����ԭ��
/*
����:��ʼ������
����ǰ:pqָ��һ������
������:�����г�ʼ��Ϊ�ն���
*/
Queue * InitializeQueue();

/*
����:ȷ�������Ƿ�Ϊ��
����ǰ:pqָ���ѳ�ʼ���Ķ���
������:�գ�����true�����򷵻�false
*/
BOOL QueueIsEmpty(const Queue * pq);

/*
����:ȷ�������Ƿ�����
����ǰ:pqָ���ѳ�ʼ���Ķ���
������:��������true�����򷵻�false
*/
BOOL QueueIsFull(const Queue * pq);

/*
����:ȷ����������Ŀ�ĸ���
����ǰ:pqָ���ѳ�ʼ���Ķ���
������:���ض�������Ŀ�ĸ���
*/
int QueueItemCount(const Queue * pq);

/*
����:�����β�������Ŀ
����ǰ:pqָ���ѳ�ʼ���Ķ��У�itemΪ�����β����ӵ���Ŀ
������:����δ���������β�������Ŀ������true��������ӣ�����false
*/
BOOL EnQueue(Item item,Queue * pq);

/*
����:�Ӷ����׶�ɾ����Ŀ
����ǰ:pqָ���ѳ�ʼ���Ķ���
������:	���зǿգ��׶˵���Ŀ��ֵ��*pItem��ɾ��������true;
		�ò���ʹ����Ϊ�գ��Ѷ�������Ϊ�ն���;
		���п�ʼΪ�գ����ı���У�����false
*/
BOOL DeQueue(Item *pItem,Queue * pq);

/*
����:��ն���
����ǰ:pqָ���ѳ�ʼ���Ķ���
������:���б����
*/
void EmptyQueue(Queue * pq);

/*
����:�����������ڶ����е�ÿһ��
����ǰ:pqָ���ѳ�ʼ���Ķ��У�pfunָ��һ������
������:��pfunָ��ĺ��������ڶ����е�ÿһ��
*/
BOOL TraverseQueue(const Queue * pq,void (*pfun)(Item item));
#endif