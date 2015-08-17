////�����������ӿ��ļ�
//#ifndef TREE_H_
//#define TREE_H_
//
//#define BOOL int
//#define true 1
//#define false 0
//
//#define SIZE 30
//#define MAXITEM 10
//
//typedef struct item{
//	char word[SIZE];
//	int ct;
//}Item;
//
//typedef struct node{
//	Item item;
//	struct node * left;
//	struct node * right;
//}Node;
//
//typedef struct tree{
//	Node * root;
//	int size;
//}Tree;
//
///*
//����:������ʼ��Ϊ��
//����ǰ:ptreeָ��һ����
//������:������ʼ��Ϊ����
//*/
//void InitalizeTree(Tree * ptree);
//
///*
//����:ȷ�����Ƿ�Ϊ��
//����ǰ:ptreeָ���ѳ�ʼ������
//������:��Ϊ�գ�����true�����򷵻�false
//*/
//BOOL TreeIsEmpty(const Tree * ptree);
//
///*
//����:ȷ�����Ƿ�����
//����ǰ:ptreeָ���ѳ�ʼ������
//������:����������true�����򷵻�false
//*/
//BOOL TreeIsFull(const Tree * ptree);
//
///*
//����:ȷ��������Ŀ�ĸ���
//����ǰ:ptreeָ���ѳ�ʼ������
//������:����������Ŀ�ĸ���
//*/
//int TreeItemCount(const Tree * ptree);
//
///*
//����:���������һ����Ŀ
//����ǰ:piָ�����ӵ���Ŀ��ptreeָ���ѳ�ʼ������
//������:��δ��������Ŀ��ӵ����У�����true�����򷵻�false
//*/
//BOOL AddItem(Item * pi,Tree * ptree);
//
///*
//����:�����в���һ����Ŀ
//����ǰ:piָ��һ����Ŀ��ptreeָ���ѳ�ʼ������
//������:�������Ŀ�����У�����true�����򷵻�false
//*/
//BOOL InTree(const Item * pi,const Tree * ptree);
//
///*
//����:������ɾ��һ����Ŀ
//����ǰ:piΪ��ɾ����Ŀ��ptreeָ���ѳ�ʼ������
//������:�ɹ�ɾ��������true�����򷵻�false
//*/
//BOOL DeleteItem(const Item * pi,Tree * ptree);
//
///*
//����:һ���������������е�ÿһ��
//����ǰ:ptreeָ���ѳ�ʼ��������pfunָ��һ������������һ��item����
//������:���ú������������е�ÿһ��
//*/
//void Traverse(const Tree * ptree,void(* pfun)(Item item));
//
///*
//����:������ɾ�����нڵ�
//����ǰ:ptreeָ���ѳ�ʼ������
//������:�����
//*/
//void DeleteAll(Tree * ptree);
//
///*
//����:�ڳ����в�����Ŀ����������Ӧ�ڵ���Ϣ
//����ǰ:ptreeָ���ѳ�ʼ������������һ��item
//������:�ҵ�Ҫ���ҵ���Ŀ��������
//*/
//void searchNode(const Tree * ptree,const Item item);
//#endif