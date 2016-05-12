#include<stdio.h>

int main()
{
	char *p;
	p = "space farers";
	printf("%s,%p,%c\n","We","are",*p);
	//输出字符串We
	//输出字符串中第一个字符的地址
	//产生所指向地址中的值
	return 0;
}