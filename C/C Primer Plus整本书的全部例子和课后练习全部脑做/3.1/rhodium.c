//金属铑衡量体重
#include<stdio.h>

int main(void)
{
	float weight;
	float value;

	printf("Enter weight in bounds:");
	scanf("%d",&weight);
	value=770*weight*14.5833;
	printf("value=%.2f \n",value);
	return 0;
}