//显示一个字符的编码值
#include<stdio.h>

int main(void)
{
	char ch;

	printf("Enter a character:");
	scanf("%c",&ch);
	printf("The code for %c is %d \n",ch,ch);
	return 0;
}