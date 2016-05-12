////list接口实现
//#include<stdio.h>
//#include<stdlib.h>
//#include"3list.h"
//
////局部函数原型
//static void CopyToList(Item item,List * plist);
//
////接口函数
//
////把列表设置为空列表
//void InitializeList(List * plist)
//{
//	plist->items = 0;
//}
////如果列表为空返回true
//BOOL ListIsEmpty(const List * plist)
//{
//	if(plist->entries[0].title[0] == '\0')
//		return true;
//	else
//		return false;
//}
////如果列表已满返回true
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
////返回节点数
//unsigned int ListItemCount(const List * plist)
//{
//	return plist->items;
//}
////创建存放节点的项目，并把它添加到plist指向的列表末尾
//BOOL AddItem(Item item,List * plist)
//{
//	CopyToList(item,plist);
//	plist->items++;
//	return true;
//}
////访问每个节点并对他们分别执行由pfun指向的函数
//void Traverse(const List * plist,void (* pfun)(Item item))
//{
//	int i = 0;
//	while(i < plist->items)
//	{
//		(*pfun)(plist->entries[i++]);//把函数作用于列表中的项
//	}
//}
////释放由malloc分配的内存,把列表指针设置为NULL
//void EmptyTheList(List * plist)
//{
//	plist->items = 0;
//}
////把一个项目赋值到一个节点中
//static void CopyToList(Item item,List * plist)
//{
//	plist->entries[plist->items] = item;
//}