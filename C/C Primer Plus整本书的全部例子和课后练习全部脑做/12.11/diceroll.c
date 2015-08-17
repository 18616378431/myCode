//掷任意个骰子，返回点数总和
#include"diceroll.h"//包含自定义头文件
#include<stdio.h>
#include<stdlib.h>//rand()、srand()定义声明
//全局变量
int roll_count = 0;//外部链接

//产生随机数
static int rollem(int sides)//这个文件的私有函数
{
	int roll;
	
	roll = rand()%sides + 1;
	++roll_count;//跟踪记录该函数的调用次数
	//printf("rand() = %d.\n",rand());
	//printf("roll = %d,roll_count = %d.\n",roll,roll_count);
	return roll;
}
//接收掷骰子次数和骰子面数计算骰子点数总和
int roll_n_dice(int dice,int sides)//掷骰子次数，骰子面数
{
	int d;
	int total = 0;
	if(sides < 2)
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if(dice < 1)
	{
		printf("Need at least 1 die.\n");
		return -1;
	}
	for(d = 0;d < dice;d++)
	{
		total += rollem(sides);
	}
	return total;
}
//计数随机函数执行次数
int rollCount()
{
	return roll_count;
}

//int main()
//{
//	//六面骰子
//	printf("%d.\n",roll_n_dice(20,6));
//	return 0;
//}
