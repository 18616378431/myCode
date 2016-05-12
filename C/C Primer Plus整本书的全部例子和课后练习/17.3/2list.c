////list接口实现
//#include<stdio.h>
//#include<stdlib.h>
//#include"2list.h"
//
////局部函数原型
//static void CopyToNode(Item item,Node * pnode);
//
////接口函数
//
////把列表设置为空列表
//void InitializeList(List * plist)
//{
//	&(*plist->head) = &(*plist->end) = NULL;
//}
////如果列表为空返回true
//BOOL ListIsEmpty(const List * plist)
//{
//	if(&(*plist->head) == NULL)
//		return true;
//	else
//		return false;
//}
////如果列表已满返回true
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
////返回节点数
//unsigned int ListItemCount(const List * plist)
//{
//	unsigned int count = 0;
//	Node * pnode = &(*plist->head);//设置到列表开始处
//
//	while(pnode != NULL)
//	{
//		++count;
//		pnode = pnode->next;
//	}
//	return count;
//}
////创建存放节点的项目，并把它添加到plist指向的列表末尾
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
//	if(scan == NULL)//如果列表为空，则将pnew放置列表头部
//	{
//		&(*plist->head) = pnew;
//	}
//	else
//	{
//		while(scan->next != NULL)
//			scan = scan->next;//找到列表结尾结尾处的节点，将该节点的next指针赋值为指向新节点的指针pnew
//		scan->next = pnew;//将pnew添加到列表结尾处
//	}
//	return true;
//}
////访问每个节点并对他们分别执行由pfun指向的函数
//void Traverse(const List * plist,void (* pfun)(Item item))
//{
//	Node * pnode = &(*plist->head);
//	while(pnode != NULL)
//	{
//		(*pfun)(pnode->item);//把函数作用于列表中的项
//		pnode = pnode->next;//前进到下一项
//	}
//}
////释放由malloc分配的内存,把列表指针设置为NULL
//void EmptyTheList(List * plist)
//{
//	Node * psave;
//	
//	while(&(*plist->head) != NULL)
//	{
//		psave = (*plist->head).next;//保存下一个节点的地址
//		free(&(*plist->head));//释放当前节点
//		&(*plist->head) = psave;//前进到下一个节点
//	}
//}
////把一个项目赋值到一个节点中
//static void CopyToNode(Item item,Node * pnode)
//{
//	pnode->item = item;
//}