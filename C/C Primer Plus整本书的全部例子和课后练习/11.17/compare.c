#include<stdio.h>
#include<string.h>//strcmp()函数原型,比较字符串是否相同，不相同返回1，空字符串返回-1，相同返回0
#define MAX 40
#define ANSWER "Grant"

int main()
{
	char try[MAX];
	int i;
	
	toup
	puts("Who is buried in Grant's tomb?");
	gets(try);
	while((i = strcmp(try,ANSWER)) != 0)
	{
		printf("strcmp返回值%d.\n",i);
		puts("No.that's wrong.Try again!");
		gets(try);
	}
	puts("That is right!");
	return 0;
}