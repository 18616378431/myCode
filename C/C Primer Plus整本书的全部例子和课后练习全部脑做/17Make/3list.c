////list�ӿ�ʵ��
//#include<stdio.h>
//#include<stdlib.h>
//#include"3list.h"
//
////�ֲ�����ԭ��
//static void CopyToList(Item item,List * plist);
//
////�ӿں���
//
////���б�����Ϊ���б�
//void InitializeList(List * plist)
//{
//	plist->items = 0;
//}
////����б�Ϊ�շ���true
//BOOL ListIsEmpty(const List * plist)
//{
//	if(plist->entries[0].title[0] == '\0')
//		return true;
//	else
//		return false;
//}
////����б���������true
//BOOL ListIsFull(const List * plist)
//{
//	BOOL full;
//	
//	if(plist->items == MAXSIZE)
//		full = true;
//	else
//		full = false;
//	return full;
//}
////���ؽڵ���
//unsigned int ListItemCount(const List * plist)
//{
//	return plist->items;
//}
////������Žڵ����Ŀ����������ӵ�plistָ����б�ĩβ
//BOOL AddItem(Item item,List * plist)
//{
//	CopyToList(item,plist);
//	plist->items++;
//	return true;
//}
////����ÿ���ڵ㲢�����Ƿֱ�ִ����pfunָ��ĺ���
//void Traverse(const List * plist,void (* pfun)(Item item))
//{
//	int i = 0;
//	while(i < plist->items)
//	{
//		(*pfun)(plist->entries[i++]);//�Ѻ����������б��е���
//	}
//}
////�ͷ���malloc������ڴ�,���б�ָ������ΪNULL
//void EmptyTheList(List * plist)
//{
//	plist->items = 0;
//}
////��һ����Ŀ��ֵ��һ���ڵ���
//static void CopyToList(Item item,List * plist)
//{
//	plist->entries[plist->items] = item;
//}