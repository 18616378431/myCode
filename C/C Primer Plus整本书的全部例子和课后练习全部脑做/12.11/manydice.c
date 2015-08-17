//模拟多次掷骰子
#include<stdio.h>
#include<stdlib.h>//srand(),rand()函数提供原型
#include<time.h>//time()函数提供原型
#include"diceroll.h"//为rollem(),roll_n_dice(),roll_count()函数提供原型

int main()
{
	int dice,sides;
	int roll;

	srand((unsigned int)time(NULL));//根据系统时间随机种子
	printf("Enter the number of sides per die.0 to stop.\n");
	while(scanf("%d",&sides) == 1 && sides > 0)
	{
		printf("How many dice?\n");
		scanf("%d",&dice);
		roll = roll_n_dice(dice,sides);
		printf("You have rolled %d using %d %d-sided dice.\n",roll,dice,sides);
		printf("How many sides?0 to stop.\n");
	}
	printf("The function rollem() called %d times.\n",rollCount());
	printf("GOOD FORTUNE TO YOU!\n");
	return 0;
}