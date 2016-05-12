//静态变量一直存储于内存中，trystat()中的自动变量fade每次调用时都惊醒初始化
#include<stdio.h>

void trystat();

int main()
{
	int count;

	for(count = 1;count <= 3;count++)
	{
		printf("Here comes interation %d\n",count);
		trystat();
	}
	return 0;
}

void trystat()
{
	int fade = 1;
	static int stay = 1;

	printf("fade = %d,stay = %d\n",fade++,stay++);
}