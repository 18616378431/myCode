//读取一个名字
#include<stdio.h>
#define MAX 81

int main()
{
	char name[MAX];//分配内存空间
	printf("Hi!What is your name?\n");
	gets(name);//把字符串放入name数组中
	printf("Nice name,%s\n",name);
	return 0;
}