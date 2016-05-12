#include<stdio.h>
#define RATE1 0.12589		//С��360kwh�ķ���
#define RATE2 0.17901		//֮���320kwh�ķ���
#define RATE3 0.20971		//����680kwh�ķ���
#define BEAK1 360.0			//���ʵ�һ���ֽ��
#define BEAK2 680.0			//���ʵڶ����ֽ��
#define BASE1 (RATE1 * BEAK1)		//360kwh�ķ���
#define BASE2 (BASE1 + (BEAK2 - BEAK1) * RATE2)		//680kwh�ķ���


int main(void)
{
	double kwh,bill;

	printf("Enter the kwh:");
	scanf("%lf",&kwh);
	if(kwh <= BEAK1)
	{
		bill = kwh * RATE1;
	}
	else if(kwh <= BEAK2)
	{
		bill = BASE1 + (kwh - BEAK1) * RATE2;
	}
	else
	{
		bill = BASE1 + BASE2 + (kwh - BEAK2) * RATE3;
	}
	printf("Your charge is $%.2f.\n",bill);
	return 0;
}