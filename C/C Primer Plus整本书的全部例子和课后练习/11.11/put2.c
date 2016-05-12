#include<stdio.h>

int put2(char * string);

int main()
{
	char *name = "Hello! World!";
	int num;

	num = put2(name);
	printf("The number of characters(include blank character) are %d\n",num);
	return 0;
}

//返回输出字符串的字符个数
int put2(char * string)
{
	int count = 0;
	while(*string != '\0')
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');
	return count;
}