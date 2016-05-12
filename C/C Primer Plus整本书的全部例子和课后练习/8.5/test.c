#include<stdio.h>

int get_int(void);

int main(void)
{
	int a;

	a = get_int();
	printf("a is %d.\n",a);
	return 0;
}

int get_int(void)
{
	int input;
	char ch;
	while(scanf("%d",&input) != 1)
	{
		while((ch = getchar()) != '\n')
		{
			putchar(ch);
		}
		printf(" is not an integer number.\nPlease input some value like 12,-1 or 39.\n");
	}
	return input;
}