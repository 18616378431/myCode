//金属铑衡量体重
#include<stdio.h>

int main(void)
{
	float weight;
	float value;

	printf("enter weight in pounds:");
	scanf_s("%f",&weight);
	value=770.00*weight*14.5833;
	printf("value=%.2f \n",value);
	return 0;
}