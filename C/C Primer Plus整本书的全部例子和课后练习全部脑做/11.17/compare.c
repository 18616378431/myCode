#include<stdio.h>
#include<string.h>//strcmp()����ԭ��,�Ƚ��ַ����Ƿ���ͬ������ͬ����1�����ַ�������-1����ͬ����0
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
		printf("strcmp����ֵ%d.\n",i);
		puts("No.that's wrong.Try again!");
		gets(try);
	}
	puts("That is right!");
	return 0;
}