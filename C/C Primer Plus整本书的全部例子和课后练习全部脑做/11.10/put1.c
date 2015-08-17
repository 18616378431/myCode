#include<stdio.h>

void put1(const char * string);

int main()
{
	char *name = "My name is WJK!And you?";

	put1(name);
	return 0;
}

void put1(const char * string)//不改变这个字符串
{
	while(*string != '\0')
		putchar(*string++);
}