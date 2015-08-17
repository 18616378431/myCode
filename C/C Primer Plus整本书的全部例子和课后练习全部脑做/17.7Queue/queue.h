#ifndef QUEUE_H_
#define QUEUE_H_

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef int Item;

#define MAXQUEUE 10

typedef struct node{
	Item item;
	struct node * next;
}Node;

typedef struct queue{
	Node * head;//ͷָ��
	Node * end;//βָ��
	int items;//��������Ŀ����
}Queue;

/*
����:��ʼ������
����ǰ:pqָ��һ������
������:�����г�ʼ��Ϊ�ն���
*/
void InitializeQueue(Queue * pq);

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
BOOL DeQueue(Item * pItem,Queue * pq);

/*
����:��ն���
����ǰ:pqָ���ѳ�ʼ���Ķ���
������:���б����
*/
void EmptyQueue(Queue * pq);

void delMore();
#endif