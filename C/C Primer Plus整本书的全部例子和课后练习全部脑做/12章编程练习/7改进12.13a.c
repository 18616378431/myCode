//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include"7�Ľ�12.13.h"
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
//		srand((unsigned int)time(NULL));//���������
//		p = (int *)malloc(sets * sizeof(int));//��̬�����ڴ�,����һ��sets��С������洢ÿ�β������ܵ���
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