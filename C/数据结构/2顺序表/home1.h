//顺序表存储结构，学生上机管理系统
#ifndef HOME1_H_
#define HOME1_H_

//#include<stdbool.h>

#define bool int
#define true 1
#define false 0

#define MAXSIZE 100
#define NAMESIZE 256

typedef struct item{
	int stuId;
	char name[NAMESIZE];
}Item;

/*
操作:构造空表
操作前:seqLen为顺序表长度
操作后:将长度设置为0
*/
void InitalizeSeq(int * seqLen);
/*
操作:判断顺序表是否已满
操作前:seqLen为当前顺序表长度
操作后:已满，返回true，否则返回false
*/
bool SeqIsFull(const int * seqLen);
/*
操作:判断顺序表是否为空
操作前:seqLen为当前顺序表长度
操作后:为空，返回true，否则返回false
*/
bool SeqIsEmpty(const int * seqLen);
/*
操作:插入元素，尾插
操作前:pSeq指向顺序表数组,seqLen为当前顺序表长度,temp为将要插入的元素
操作后:向数组末尾添加一个元素，插入成功，返回true，否则返回false
*/
bool AddItem(Item * pSeq,int * seqLen,const Item * temp);
/*
操作:查找指定元素
操作前:pSeq指向顺序表，temp为带查找元素
操作后:找到目标元素，返回true，否则返回false，并提示信息
*/
bool SeekItem(Item * pSeq,int * seqLen, Item temp);
/*
操作:删除顺序表的第i的元素
操作前:pSeq指向顺序表，i为要删除的元素
操作后:如果元素i在表中，执行删除操作，返回true，否则返回false
*/
bool DeleteItem(Item * pSeq,int * seqLen,int i);
/*
操作:清空线性表
操作前:seqLen为顺序表长度
操作后:将顺序表长度置为0
*/
void EmptyList(int * seqLen);
/*
操作:将指定函数作用于顺序表
操作前:pSeq指向一个顺序表数组
操作后:将指定函数作用于顺序表中的每一个元素
*/
void Traverse(Item * pSeq,int * seqLen,void (*pfun)(Item item));
#endif