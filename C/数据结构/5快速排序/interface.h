//接口
//汽车租赁系统快速排序
//顺序表实现
#ifndef INTERFACE_H_
#define INTERFACE_H_

#define BOOL int
#define true 1
#define false 0

#define tradeNameLen 30

typedef struct item{
	int carId;
	char tradeMark[tradeNameLen];
	BOOL flag;
}Item;

typedef struct list{
	Item item;
}List;

/*
操作:快速排序顺序表,划分算法
操作前:pList指向初始化的顺序表
操作后:排序顺序表
*/
int partition(List * pList,int low,int high);
/*
操作:递归调用快速排序
操作前:pList指向初始化的顺序表
操作后:最终排序顺序表
*/
void quickSort(List * pList,int low,int high);
#endif