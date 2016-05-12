//向函数传递结构成员
#include<stdio.h>
#define LEN 51

double sum(double a,double b);

struct funds{
	char bank[LEN];
	double bankfund;
	char save[LEN];
	double savefund;
};

int main()
{
	//初始化结构成员
	struct funds stan = {
			"Garlic",
			3024.72,
			"Lucky's Saving and Loan",
			9237.11
	};

	printf("stan has a total of $%.2f.\n",sum(stan.bankfund,stan.savefund));
	return 0;
}
double sum(double a,double b)
{
	return (a + b);
}