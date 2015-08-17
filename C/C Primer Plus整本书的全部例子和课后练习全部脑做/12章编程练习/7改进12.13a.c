//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include"7改进12.13.h"
//
//int main()
//{
//	int sets;
//	int dice;
//	int sides;
//	int i;
//	int *p;
//
//	printf("Enter the number of sets(q to stop):\n");
//	while(scanf("%d",&sets) == 1)
//	{
//		printf("How many sides and how many dice?\n");
//		scanf("%d%d",&sides,&dice);
//		srand((unsigned int)time(NULL));//随机化种子
//		p = (int *)malloc(sets * sizeof(int));//动态分配内存,创建一个sets大小的数组存储每次产生的总点数
//		for(i = 0;i < sets;i++)
//		{
//			p[i] = roll_n_dice(dice,sides);
//		}
//		printf("Here are %d sets of %d %d-sided throws.\n",sets,dice,sides);
//		for(i = 0;i < sets;i++)
//		{
//			printf("%4d",p[i]);
//		}
//		printf("\nEnter the number of sets(q to stop):\n");
//	}
//	printf("The rollem() function called %d times.\n",roll_count);
//	printf("GOOD FORTUNE TO YOU!\n");
//	return 0;
//}