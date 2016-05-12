//#include<stdio.h>
//#include<stdlib.h>
//
//extern int roll_count;
//
////按边数产生一个随机点数
//static int rollem(int sides)
//{
//	int roll;
//
//	roll = rand() % sides + 1;
//	++roll_count;
//	return roll;
//}
////计算掷dice次sides面骰子的总点数
//int roll_n_dice(int dice,int sides)
//{
//	int d;
//	int total = 0;
//
//	if(sides < 2)
//	{
//		printf("至少需要两边.\n");
//		return -2;
//	}
//	if(dice < 1)
//	{
//		printf("至少需要掷一次骰子.\n");
//		return -1;
//	}
//	for(d = 0;d < dice;d++)
//	{
//		total += rollem(sides);
//	}
//	return total;
//}