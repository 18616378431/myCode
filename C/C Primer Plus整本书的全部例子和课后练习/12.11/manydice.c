//ģ����������
#include<stdio.h>
#include<stdlib.h>//srand(),rand()�����ṩԭ��
#include<time.h>//time()�����ṩԭ��
#include"diceroll.h"//Ϊrollem(),roll_n_dice(),roll_count()�����ṩԭ��

int main()
{
	int dice,sides;
	int roll;

	srand((unsigned int)time(NULL));//����ϵͳʱ���������
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