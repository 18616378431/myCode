#include<stdio.h>

int main(void)
{
	double sum;
	int i;
	sum = 100;
	i = 0;
	while(sum > 0 )
	{
		sum = sum + sum*0.08 - 10;
		i++;
	}
	printf("%.2f\n%d\n",sum,i);
	return 0;
}