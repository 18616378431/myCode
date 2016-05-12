#include<stdio.h>

//函数声明
char get_choice();		//获取输入选项
char get_first();		//获取第一个非空字符
void count(void);		//C选项计数
int get_int();		//获取整数

int main(void)
{
	int choice;

	while((choice = get_choice()) != 'q')
	{
		switch(choice)
		{
		case 'a':
			printf("Buy low,sell high!\n");
			break;
		case 'b':
			printf("\a");
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
//获取选择项
char get_choice()
{
	char ch;
	
	printf("Enter the letter your choice:\n");
	printf("a.advice\tb.bell\n");
	printf("c.count\tq.quit\n");

	ch = get_first();
	while(ch < 'a' || ch > 'c' && ch != 'q')
	{
		printf("Please response with a,b,c or q!\n");
		ch = get_first();
	}
	return ch;
}
//获取第一个非空或不是\n的字符
char get_first()
{
	char cr;		//获取的第一个非空字符

	while((cr = getchar()) == ' ' || cr == '\n')		//跳过有效输入之前的空白符和换行符
	{
		continue;
	}
	while(getchar() != '\n')		//跳过剩余字符
	{
		continue;
	}
	return cr;
}

void count(void)
{
	int n;		//存储获取整数
	int i;		//循环上界
	
	n = get_int();
	for(i=1;i<=n;i++)
	{
		printf("%d\n",i);
	}
	//while(getchar() != '\n')		//跳过该行剩余字符
	//{
	//	continue;
	//}
}
//获取一个整数
int get_int()
{
	int input;		//存储正确整数
	char ch;		//存储丢弃非整数
	
	printf("Count how far?Enter an integer:");
	while(scanf("%d",&input) != 1)
	{
		while((ch = getchar()) != '\n')
		{
			putchar(ch);
		}
		printf(" is not an integer.\n");
	}

	return input;
}