////list�ӿ�ʵ��
//#include<stdio.h>
//#include<stdlib.h>
//#include"2list.h"
//
////�ֲ�����ԭ��
//static void CopyToNode(Item item,Node * pnode);
//
////�ӿں���
//
////���б�����Ϊ���б�
//void InitializeList(List * plist)
//{
//	&(*plist->head) = &(*plist->end) = NULL;
//}
////����б�Ϊ�շ���true
//BOOL ListIsEmpty(const List * plist)
//{
//	if(&(*plist->head) == NULL)
//		return true;
//	else
//		return false;
//}
////����б���������true
//BOOL ListIsFull(const List * plist)
//{
//	Node * pt;
//	BOOL full;
//	
//	pt = (Node *)malloc(sizeof(Node));
//	if(pt == NULL)
//		full = true;
//	else
//		full = false;
//	free(pt);
//	return full;
//}
////���ؽڵ���
//unsigned int ListItemCount(const List * plist)
//{
//	unsigned int count = 0;
//	Node * pnode = &(*plist->head);//���õ��б�ʼ��
//
//	while(pnode != NULL)
//	{
//		++count;
//		pnode = pnode->next;
//	}
//	return count;
//}
////������Žڵ����Ŀ����������ӵ�plistָ����б�ĩβ
//BOOL AddItem(Item item,List * plist)
//{
//	Node * pnew;
//	Node * scan = &(*plist->head);
//
//	pnew = (Node *)malloc(sizeof(Node));
//	if(pnew == NULL)
//		return false;
//	CopyToNode(item,pnew);
//	pnew->next = NULL;
//	if(scan == NULL)//����б�Ϊ�գ���pnew�����б�ͷ��
//	{
//		&(*plist->head) = pnew;
//	}
//	else
//	{
//		while(scan->next != NULL)
//			scan = scan->next;//�ҵ��б��β��β���Ľڵ㣬���ýڵ��nextָ�븳ֵΪָ���½ڵ��ָ��pnew
//		scan->next = pnew;//��pnew��ӵ��б��β��
//	}
//	return true;
//}
////����ÿ���ڵ㲢�����Ƿֱ�ִ����pfunָ��ĺ���
//void Traverse(const List * plist,void (* pfun)(Item item))
//{
//	Node * pnode = &(*plist->head);
//	while(pnode != NULL)
//	{
//		(*pfun)(pnode->item);//�Ѻ����������б��е���
//		pnode = pnode->next;//ǰ������һ��
//	}
//}
////�ͷ���malloc������ڴ�,���б�ָ������ΪNULL
//void EmptyTheList(List * plist)
//{
//	Node * psave;
//	
//	while(&(*plist->head) != NULL)
//	{
//		psave = (*plist->head).next;//������һ���ڵ�ĵ�ַ
//		free(&(*plist->head));//�ͷŵ�ǰ�ڵ�
//		&(*plist->head) = psave;//ǰ������һ���ڵ�
//	}
//}
////��һ����Ŀ��ֵ��һ���ڵ���
//static void CopyToNode(Item item,Node * pnode)
//{
//	pnode->item = item;
//}