#include<stdio.h>
#include<string.h>//声明strcat()函数，char * 类型,连接两个字符串，返回第二个字符串首字符的地址
#define SIZE 80


int main()
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";

	puts("What is your favorite flower?");
	gets(flower);
	strcat(flower,addon);
	puts(flower);
	puts(addon);
	return 0;
}