//#include<stdio.h>
//#include<stdlib.h>
//
//extern int roll_count;
//
////����������һ���������
//static int rollem(int sides)
//{
//	int roll;
//
//	roll = rand() % sides + 1;
//	++roll_count;
//	return roll;
//}
////������dice��sides�����ӵ��ܵ���
//int roll_n_dice(int dice,int sides)
//{
//	int d;
//	int total = 0;
//
//	if(sides < 2)
//	{
//		printf("������Ҫ����.\n");
//		return -2;
//	}
//	if(dice < 1)
//	{
//		printf("������Ҫ��һ������.\n");
//		return -1;
//	}
//	for(d = 0;d < dice;d++)
//	{
//		total += rollem(sides);
//	}
//	return total;
//}