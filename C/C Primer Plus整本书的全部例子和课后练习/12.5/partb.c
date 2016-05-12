#include<stdio.h>

//全局变量
extern int count;//引用声明，外部链接
static int total = 0;//静态定义，内部链接
//函数声明
void accumulate(int k);

void accumulate(int k)//k具有代码块作用域
{
	static int subtotal = 0;//静态、空链接

	if(k <= 0)
	{
		printf("Loop cycle %d.\n",count);
		printf("subtotal:%d,total:%d.\n",subtotal,total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	}
}