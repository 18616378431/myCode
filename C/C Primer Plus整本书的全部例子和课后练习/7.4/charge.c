#include<stdio.h>
#define RATE1 0.12589		//小于360kwh的费率
#define RATE2 0.17901		//之后的320kwh的费率
#define RATE3 0.20971		//大于680kwh的费率
#define BEAK1 360.0			//费率第一个分界点
#define BEAK2 680.0			//费率第二个分界点
#define BASE1 (RATE1 * BEAK1)		//360kwh的费用
#define BASE2 (BASE1 + (BEAK2 - BEAK1) * RATE2)		//680kwh的费用


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