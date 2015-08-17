////栈接口文件
//#ifndef STACK_H_
//#define STACK_H_
//
//#define MAX 256
//
//#define BOOL int
//#define true 1
//#define false 0
//
//typedef char Item;
//
//typedef struct stack{
//	Item item[MAX];
//	int top;//第一个空位的索引
//}Stack;
//
///*
//操作:初始化栈为空
//操作前:ps指向一个栈
//操作后:将栈初始化为空栈
//*/
//void InitalizeStack(Stack * ps);
//
///*
//操作:确定栈是否为空
//操作前:ps指向已初始化的栈
//操作后:栈为空，返回true，否则返回false
//*/
//BOOL StackIsEmpty(const Stack * ps);
//
///*
//操作:确定栈是否已满
//操作前:ps指向已初始化的栈
//操作后:栈满，返回true，否则返回false
//*/
//BOOL StackIsFull(const Stack * ps);
//
///*
//操作:向栈顶添加一个项目
//操作前:ps指向已初始化的栈，item为要添加的项目
//操作后:向栈顶添加一个项目，如果栈为空，将项目添加进去，返回true，如果栈满，返回false
//*/
//BOOL Push(Item * item,Stack * ps);
//
///*
//操作:从栈顶删除一个项目
//操作前:ps指向已初始化的栈
//操作后:如果栈不为空,删除栈顶项，返回true，如果该操作使栈为空，重置栈为空;如果栈开始就为空，返回false
//*/
//BOOL Pop(Stack * ps);
//
///*
//操作:清空栈
//操作前:ps指向已初始化的栈
//操作后:栈被清空
//*/
//void EmptyStack(Stack * ps);
//#endif