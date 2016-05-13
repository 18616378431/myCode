//�ӿ�
#ifndef HOME_H_
#define HOME_H_

//#include<stdbool.h>

#ifndef STDBOOL_H_
#define STDBOOL_H_

#define bool int
#define true 1
#define false 0

#endif

#define NSIZE 20
//�������ƺ�Ʒ��
typedef struct carName{
	int carid;
	char trademark[NSIZE];
	bool flag;//�Ƿ�������
}Item;

typedef struct node{
	Item item;
	struct node * next;
}Node;

typedef struct list{
	Node * head;
	Node * end;
	int size;
}List;

/*
����:��ʼ���б�
����ǰ:plistָ��һ���б�
������:���б��ʼ��Ϊ���б�
*/
void InitalizeList(List * plist);

/*
����:ȷ���б��Ƿ�Ϊ��
����ǰ:plistָ���ѳ�ʼ�����б�
������:�б�Ϊ�գ�����true�����򷵻�false
*/
bool ListIsEmpty(const List * plist);

/*
����:ȷ���б��Ƿ�����
����ǰ:plistָ���ѳ�ʼ�����б�
������:�б�����������true�����򷵻�false
*/
bool ListIsFull(const List * plist);

/*
����:ȷ���б��нڵ������
����ǰ:plistָ���ѳ�ʼ�����б�
������:�����б�����Ŀ������
*/
int ListItemCount(const List * plist);

/*
����:���б��������Ŀ
����ǰ:plistָ���ѳ�ʼ�����б�
������:����б�δ��������Ŀ��ӵ��б��У�����true�����򷵻�false
*/
bool AddItemToList(const Item * pitem,List * plist);

/*
����:���б��׶�ɾ���ڵ�
����ǰ:plistָ���ѳ�ʼ�����б�
������:�б�Ϊ�գ���Ŀ��ڵ�ɾ��������false�������ɾ������ʹ�б�Ϊ�գ������б�����true�����򷵻�false
*/
bool DeleteItemFromList(List * plist);

/*
����:��ָ�������������б��е�ÿһ��
����ǰ:plistָ���ѳ�ʼ�����б�pfunָ����ָ���ĺ�����pfunΪ����һ��item�������޷���ֵ�ĺ���
������:��pfunָ��ĺ����������б��е�ÿһ��
*/
void Traverse(List * plist,void (*pfun)(Item item));

/*
����:����б�
����ǰ:plistָ���ѳ�ʼ�����б�
������:���б����
*/
void EmptyList(List * plist);
#endif