//接口
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
//汽车名称和品牌
typedef struct carName{
	int carid;
	char trademark[NSIZE];
	bool flag;//是否已租赁
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
操作:初始化列表
操作前:plist指向一个列表
操作后:将列表初始化为空列表
*/
void InitalizeList(List * plist);

/*
操作:确定列表是否为空
操作前:plist指向已初始化的列表
操作后:列表为空，返回true，否则返回false
*/
bool ListIsEmpty(const List * plist);

/*
操作:确定列表是否已满
操作前:plist指向已初始化的列表
操作后:列表已满，返回true，否则返回false
*/
bool ListIsFull(const List * plist);

/*
操作:确定列表中节点的数量
操作前:plist指向已初始化的列表
操作后:返回列表中项目的数量
*/
int ListItemCount(const List * plist);

/*
操作:向列表中添加项目
操作前:plist指向已初始化的列表
操作后:如果列表未满，将项目添加到列表中，返回true，否则返回false
*/
bool AddItemToList(const Item * pitem,List * plist);

/*
操作:从列表首端删除节点
操作前:plist指向已初始化的列表
操作后:列表不为空，将目标节点删除，返回false，如果该删除操作使列表为空，重置列表，返回true，否则返回false
*/
bool DeleteItemFromList(List * plist);

/*
操作:将指定函数作用于列表中的每一项
操作前:plist指向已初始化的列表，pfun指向用指定的函数，pfun为接收一个item参数，无返回值的函数
操作后:将pfun指向的函数作用于列表中的每一项
*/
void Traverse(List * plist,void (*pfun)(Item item));

/*
操作:清空列表
操作前:plist指向已初始化的列表
操作后:将列表清空
*/
void EmptyList(List * plist);
#endif