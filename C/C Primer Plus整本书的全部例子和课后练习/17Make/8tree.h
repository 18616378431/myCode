//二叉搜索树接口文件
#ifndef TRRR_H_
#define TREE_H_

#include"8list.h"

#define MAXITEMS 10

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct node{
	Queue * queue;
	struct node * left;//左子节点
	struct node * right;//右子节点
}Node;

typedef struct tree{
	Node * root;//树的根节点指针
	int size;//树的大小
}Tree;

//函数原型
void print();
/*
操作:把一个树初始化为空树
操作前:ptree指向一个树
操作后:该树初始化为空树
*/
void InitializeTree(Tree * ptree);
/*
操作:确定树是否为空
操作前:ptree指向一个已经初始化的树
操作后:为空返回true，否则返回false
*/
BOOL TreeIsEmpty(const Tree * ptree);
/*
操作:确定树是否已满
操作前:ptree指向已经初始化的树
操作后:树已满，返回true，否则返回false
*/
BOOL TreeIsFull(const Tree * ptree);
/*
操作:确定树中项目的个数
操作前:ptree指向已经初始化的树
操作后:返回树中项目的个数
*/
int TreeItemCount(const Tree * ptree);
/*
操作:向树中添加一个项目
操作前:pi为待添加项目的地址，ptree指向已经初始化的树
操作后:如果可能，该函数将项目添加到树中，返回true，否则返回false
*/
BOOL AddItem(const Item * pi,Tree * ptree);
/*
操作:在树中查找一个项目
操作前:pi指向要查找的项目，ptree指向已经初始化的树
操作后:如果该项目在树中，返回true，否则返回false
*/
BOOL InTree(const Item * pi,const Tree * ptree,void (* pfun)(Item item));
/*
操作:从树中删除一个项目
操作前:pi为待删除项目的地址，ptree指向已经初始化的树
操作后:如果可能，从项目中删除该项，返回true，否则返回false
*/
BOOL DeleteItem(Item * pi,Tree * ptree);
/*
操作:把一个项目作用于树的每一项
操作前:ptree指向已经初始化的树，pfun指向无返回值的函数，该函数接收一个Item参数
操作后:pfun指向的函数被作用于树中的每一个项目一次
*/
void Traverse(const Tree * ptree,void (* pfun)(Item item));
/*
操作:从树中删除所有节点
操作前:ptree指向一个已经初始化的树
操作后:将该树置为空
*/
void DeleteAll(Tree * ptree);
#endif