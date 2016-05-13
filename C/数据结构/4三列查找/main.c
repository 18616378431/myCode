//除留余数法建立hash散列矩阵
#include<stdio.h>
#include"interface.h"

//局部函数
char Menu();
void delMore();
void InsertItem(HashList hl);
void SearchItem(HashList hl);
void DeleteItem(HashList hl);

int main()
{
	HashList hl;
	char choose;

	InitHashList(hl);
	while((choose = Menu()) != 'd')
	{
		switch(choose)
		{
		case 'a'://插入数据
			InsertItem(hl);
			break;
		case 'b'://查询数据
			SearchItem(hl);
			break;
		case 'c'://删除数据
			DeleteItem(hl);
			break;
		default:
			puts("请输入a、b、c来进行选择操作");
			break;
		}
	}
	ClearHashList(hl);
	return 0;
}
//显示菜单并获取用户选择
char Menu()
{
	char ch;

	puts("==========================================");
	puts("a.插入汽车租赁数据\tb.查询汽车租赁数据");
	puts("c.删除指定汽车相关数据\td.退出");
	puts("==========================================");
	ch = getchar();
	delMore();
	return ch;
}
//清楚输入行剩余项
void delMore()
{
	while(getchar() != '\n')
		continue;
}
//插入数据
void InsertItem(HashList hl)
{
	Item item;

	puts("请输入汽车相关数据:");
	puts("please enter the car id:");
	scanf("%d",&item.carId);
	delMore();
	puts("please enter the trade mark:");
	gets(item.tradeMark);
	if(!InsertItemIntoHashList(hl,item))
	{
		puts("插入失败");
	}
	else
	{
		puts("插入成功");
	}
}
//查询数据
void SearchItem(HashList hl)
{
	Item item;
	int result;

	puts("请输入要查询的车牌号:");
	scanf("%d",&item.carId);
	delMore();
	result = LocateItemFromHashList(hl,item);
	if(result != -1)
	{
		printf("查找成功,数据位置为%d!.\n",result);
	}
	else
	{
		puts("查找失败!");
	}
}
//删除数据
void DeleteItem(HashList hl)
{
	Item item;

	puts("请输入要删除的车牌号:");
	scanf("%d",&item.carId);
	delMore();
	DeleteItemFromHashList(hl,item);
}