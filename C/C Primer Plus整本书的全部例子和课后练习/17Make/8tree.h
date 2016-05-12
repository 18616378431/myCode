//�����������ӿ��ļ�
#ifndef TRRR_H_
#define TREE_H_

#include"8list.h"

#define MAXITEMS 10

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct node{
	Queue * queue;
	struct node * left;//���ӽڵ�
	struct node * right;//���ӽڵ�
}Node;

typedef struct tree{
	Node * root;//���ĸ��ڵ�ָ��
	int size;//���Ĵ�С
}Tree;

//����ԭ��
void print();
/*
����:��һ������ʼ��Ϊ����
����ǰ:ptreeָ��һ����
������:������ʼ��Ϊ����
*/
void InitializeTree(Tree * ptree);
/*
����:ȷ�����Ƿ�Ϊ��
����ǰ:ptreeָ��һ���Ѿ���ʼ������
������:Ϊ�շ���true�����򷵻�false
*/
BOOL TreeIsEmpty(const Tree * ptree);
/*
����:ȷ�����Ƿ�����
����ǰ:ptreeָ���Ѿ���ʼ������
������:������������true�����򷵻�false
*/
BOOL TreeIsFull(const Tree * ptree);
/*
����:ȷ��������Ŀ�ĸ���
����ǰ:ptreeָ���Ѿ���ʼ������
������:����������Ŀ�ĸ���
*/
int TreeItemCount(const Tree * ptree);
/*
����:���������һ����Ŀ
����ǰ:piΪ�������Ŀ�ĵ�ַ��ptreeָ���Ѿ���ʼ������
������:������ܣ��ú�������Ŀ��ӵ����У�����true�����򷵻�false
*/
BOOL AddItem(const Item * pi,Tree * ptree);
/*
����:�����в���һ����Ŀ
����ǰ:piָ��Ҫ���ҵ���Ŀ��ptreeָ���Ѿ���ʼ������
������:�������Ŀ�����У�����true�����򷵻�false
*/
BOOL InTree(const Item * pi,const Tree * ptree,void (* pfun)(Item item));
/*
����:������ɾ��һ����Ŀ
����ǰ:piΪ��ɾ����Ŀ�ĵ�ַ��ptreeָ���Ѿ���ʼ������
������:������ܣ�����Ŀ��ɾ���������true�����򷵻�false
*/
BOOL DeleteItem(Item * pi,Tree * ptree);
/*
����:��һ����Ŀ����������ÿһ��
����ǰ:ptreeָ���Ѿ���ʼ��������pfunָ���޷���ֵ�ĺ������ú�������һ��Item����
������:pfunָ��ĺ��������������е�ÿһ����Ŀһ��
*/
void Traverse(const Tree * ptree,void (* pfun)(Item item));
/*
����:������ɾ�����нڵ�
����ǰ:ptreeָ��һ���Ѿ���ʼ������
������:��������Ϊ��
*/
void DeleteAll(Tree * ptree);
#endif