#include<stdio.h>

void put1(const char * string);

int main()
{
	char *name = "My name is WJK!And you?";

	put1(name);
	return 0;
}

void put1(const char * string)//���ı�����ַ���
{
	while(*string != '\0')
		putchar(*string++);
}