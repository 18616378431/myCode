#include <stdio.h>

long long fib(long long n);

int main()
{
	int i;
	for(i = 1;i <= 50;i++)
	{
		printf("%d:%lld\n",i,fib(i));
	}

	return 0;
}

long long fib(long long n)
{
	if(n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 2) + fib(n - 1);
	}
}
