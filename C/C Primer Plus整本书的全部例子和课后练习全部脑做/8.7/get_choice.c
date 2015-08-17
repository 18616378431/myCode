#include<stdio.h>

//函数声明
char get_choice(void);		//获取选择的菜单项
char get_first(void);		//获取一行的第一个字符
void count(void);		//c选项的计数函数
int get_int();		//获取一个整数

int main(void)
{
	int choice;

	while((choice = get_choice()) != 'q')
	{
		switch(choice)
		{
		case 'a':
			printf("Buy low,sel high!\n");
			break;
		case 'b':
			putchar('\a');
			break;
		case 'c':
			count();
			break;
		default:
			printf("Program error!\n");
			break;
		}
	}
	return 0;
}
//返回a,b,c,q
char get_choice(void)
{
	int ch;
	printf("Enter the letter of your choice:\n");
	printf("a.advice\tb.bell\nc.count\t\tq.quit\n");
	ch = get_first();
	while(ch < 'a' || ch > 'c' && ch != 'q')
	{
		printf("Please response a,b,c or q.\n");
		ch = get_first();
	}
	return ch;
}
//只获取一行的第一个字符，丢弃其余字符
char get_first(void)
{
	char cr;		//存储用户输入字符
	
	while((cr = getchar()) == ' ' || cr == '\n')
	{
		continue;
	}
	/*if(cr == '\n')
	{
		cr = getchar();
	}
	else
	{
		;
	}*/
	while(getchar() != '\n')		//跳过本行剩余部分
	{
		continue;
	}
	return cr;
}
//计数
void count(void)
{
	int n,i;

	n = get_int();
	for(i=1;i<=n;i++)
	{
		printf("%d.\n",i);
	}
	//while(getchar() != '\n')		//跳过scanf()获取输入的残余\n字符
	//{
	//	continue;
	//}
}
//获取一个整数
int get_int()
{
	int input;
	char ch;		//存储错误字符
	
	printf("Count how far?Enter an integer:");
	while(scanf("%d",&input) != 1)
	{
		while((ch = getchar()) != '\n')
		{
			putchar(ch);
		}
		printf(" is not an integer.Please try again.\n");
	}
	return input;
}