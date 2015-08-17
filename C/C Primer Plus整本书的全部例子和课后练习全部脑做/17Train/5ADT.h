#ifndef 5ADT_H_
#define 5ADT_H_

/*BOOL类型C语言定义*/
#define BOOL int
#define TRUE 1
#define FALSE 0

#define MAXSTACK 100

typedef int Item;

typedef struct stack{
	Item item[MAXSTACK];
	int top;//第一个空位的索引
}Stack;

/*
操作:将栈初始化为空
操作前:ps指向栈
操作后:栈被初始化为空
*/
void InitalizeStack(Stack * ps);
/*
操作:确定栈是否为空
操作前:ps指向已初始化的栈
操作后:为空，返回true，否则返回false
*/
BOOL StackIsEmpty(const Stack * ps);
/*
操作:确定栈是否已满
操作前:ps指向已初始化的栈
操作后:已满，返回true，否则返回false
*/
BOOL StackIsFull(const Stack * ps);
/*
操作:向栈顶添加一项
操作前:ps指向已初始化的栈，item为要放到栈顶的项目
操作后:如果栈不为空，将item放到栈顶，返回true，否则，返回false
*/
BOOL Push(Item item,Stack * ps);
/*
操作:从栈顶删除一项
操作前:ps指向已初始化的栈
操作后:如果栈不为空，将栈顶项目赋值到pitem，并删除，返回true，如果该操作后使栈为空，重置栈;如果栈开始就位空，函数返回false
*/
BOOL Pop(Stack * ps,Item * pItem);
/*
操作:清空栈
操作前:ps指向已初始化的栈
操作后:如果栈不为空，清空栈，为空则不进行任何操作
*/
void EmptyStack(Stack * ps);
#endif