//×ªÒå×Ö·û
#include<stdio.h>

int main(void)
{
	float salary;
	printf("Enter your desired salary:");
	printf("$_______\b\b\b\b\b\b\b");
	scanf_s("%f",&salary);
	printf("\n\t$%.2f a month is %.2f a year.",salary,salary*12.0);
	printf("\rGee! \n");
	return 0;
}