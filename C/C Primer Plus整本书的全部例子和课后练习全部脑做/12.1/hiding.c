//自动变量的作用域
#include<stdio.h>

int main()
{
	auto int x = 30;//外层定义

	printf("outer x = %d\n",x);
	{
		int x = 77;//内层定义
		printf("inner x = %d\n",x);
	}

	printf("outer x = %d\n",x);

	while(x++ < 33)//使用的是外层代码块的x值
	{
		int x = 100;//内层
		x++;
		printf("inner while loop x = %d\n",x);
	}

	printf("outer x = %d\n",x);
	return 0;
}