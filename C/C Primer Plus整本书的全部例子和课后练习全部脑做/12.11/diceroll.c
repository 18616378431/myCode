//����������ӣ����ص����ܺ�
#include"diceroll.h"//�����Զ���ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>//rand()��srand()��������
//ȫ�ֱ���
int roll_count = 0;//�ⲿ����

//���������
static int rollem(int sides)//����ļ���˽�к���
{
	int roll;
	
	roll = rand()%sides + 1;
	++roll_count;//���ټ�¼�ú����ĵ��ô���
	//printf("rand() = %d.\n",rand());
	//printf("roll = %d,roll_count = %d.\n",roll,roll_count);
	return roll;
}
//���������Ӵ��������������������ӵ����ܺ�
int roll_n_dice(int dice,int sides)//�����Ӵ�������������
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
//�����������ִ�д���
int rollCount()
{
	return roll_count;
}

//int main()
//{
//	//��������
//	printf("%d.\n",roll_n_dice(20,6));
//	return 0;
//}
