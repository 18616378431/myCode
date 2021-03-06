#include<stdio.h>

//函数声明
void report_count();
void accumulate(int k);//默认为外部的
//全局变量
int count = 0;//文件作用域,具有外部链接

int main()
{
	int value;//自动变量
	register int i;//寄存器变量

	printf("Enter a positive integer(0 to quit):");
	while(scanf("%d",&value) == 1 && value > 0)
	{
		++count;//使用文件作用域变量
		for(i = value;i >= 0;i--)
		{
			accumulate(i);
		}
		printf("Enter a positive integer(0 to quit):");
	}
	report_count();
	return 0;
}

void report_count()
{
	printf("Loop executed %d times.\n",count);
}