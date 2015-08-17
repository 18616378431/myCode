//Fibonacci数列
#include<stdio.h>

int Fibonacci(int n);

int main()
{
	int p;
	printf("斐波那契数列,前两位为,1 1,请输入大于2的整数:\n");
	while(scanf("%d",&p) == 1)
	{
		Fibonacci(p);
	}
	//printf("%d.\n",Fibonacci(p));
	return 0;
}

int Fibonacci(int n)
{
	int a = 1;
	int b = 1;
	int sum = 0;
	if(n > 2)
	{
		/*f(1) = f(2) = 1;
		return Fibonacci(n -1) + Fibonacci(n - 2);
		n = 5;
		f(5 - 1) + f(5 - 2) = f(4) + f(3);
		f(4 - 1) + f(4 - 2) = f(3) + f(2);
		f(3 - 1) + f(3 - 2) = f(2) + f(1);
		f(2) + f(1) = 1 + 1 = 2;
		f(3) = f(2) + f(1) = 2;
		f(4) = f(3) + f(2) = 2 + 1 = 3;
		f(5) = f(4) + f(3) = 3 + 2 = 5;
		1 + 1 = 2;
		1 + 2 = 3;
		2 + 3 = 5;
		3 + 5 = 8;*/
		printf("%d  %d  ",a,b);
		for(;n > 2 ;n--)
		{
			sum = a + b;
			printf("%d  ",sum);
			a = b;
			b = sum;
		}
		putchar('\n');
		return sum;
	}
	else
	{
		return 1;
	}
}