//使用结构数组的函数
#include<stdio.h>
#define LEN 41
#define N 2

struct funds{
	char bank[LEN];
	double bankfund;
	char save[LEN];
	double savefund;
};

double sum(const struct funds money[],int n);

int main()
{
	struct funds jones[N] = {
		{"Garlic",3024.72,"Lucky",9237.11},
		{"Honest",3534.28,"Party",3203.89}};
	
	printf("The Joneses have a total of $%.2f.\n",sum(jones,N));
	return 0;
}
double sum(const struct funds money[],int n)
{
	int i;
	double total = 0;

	for(i = 0;i < n;i++)
	{
		total += money[i].bankfund + money[i].savefund;
	}
	return total;
}