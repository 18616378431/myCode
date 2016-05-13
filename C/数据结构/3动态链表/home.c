//实现文件
#include<stdio.h>
#include<stdlib.h>
#include"home.h"

//局部函数声明
static Node * MakeNode(const Item * pitem);

//初始化列表
void InitalizeList(List * plist)
{
	plist->head = plist->end = NULL;
	plist->size = 0;
}
//确定列表是否为空
bool ListIsEmpty(const List * plist)
{
	if (plist->head == NULL || plist->size == 0)
		return true;
	else
		return false;
}
//确定列表是否已满
bool ListIsFull(const List * plist)
{
	Node * new_node;

	new_node = (Node *)malloc(sizeof(Node));

	if (new_node == NULL)
		return true;
	else
		free(new_node);
	return false;
}
//确定列表中项目的数量
int ListItemCount(const List * plist)
{
	return plist->size;
}
//向列表中添加项目
bool AddItemToList(const Item * pitem, List * plist)
{
	Node * new_node;

	if (ListIsFull(plist))
	{
		fprintf(stderr,"List is full!\n");
		exit(EXIT_FAILURE);
	}
	new_node = MakeNode(pitem);
	if (new_node == NULL)
	{
		fprintf(stderr,"Fail yo create node.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (ListIsFull(plist))
		{
			fprintf(stderr,"List is full.\n");
			exit(EXIT_FAILURE);
		}
		if (ListIsEmpty(plist))
		{
			plist->head = new_node;
		}
		else
		{
			plist->end->next = new_node;
		}
		new_node->next = NULL;
		plist->end = new_node;
		plist->size++;
	}
	return true;
}
//从列表首端删除项目
bool DeleteItemFromList(List* plist)
{
	Node * save;

	if (ListIsEmpty(plist))
	{
		fprintf(stderr,"List is empty!\n");
		return false;
	}
	save = plist->head;
	plist->head = plist->head->next;
	free(save);
	plist->size--;
	if (plist->size == 0)
		plist->end = NULL;
	return true;
}
//将指定函数作用于列表中的每一项
void Traverse(List * plist, void(*pfun)(Item item))
{
	Node * pnode = plist->head;

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}
//清空列表
void EmptyList(List * plist)
{
	Node * save;

	while (plist->head != NULL)
	{
		save = plist->head->next;
		free(plist->head);
		plist->head = save;
	}
}

/*局部函数*/
static Node * MakeNode(const Item * pitem)
{
	Node * new_node;

	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->item = *pitem;
	}
	else
	{
		fprintf(stderr,"Failing create node int MakeNode()!\n");
	}
	return new_node;
}