//#include<stdio.h>
//#include<ctype.h>
//#define SIZE 81
//
//void getnchar(char * str,int num);
//
//int main()
//{
//	char input[SIZE];
//	int n;//读入的字符数
//
//	puts("Enter the number of your string:");
//	scanf("%d",&n);
//	getchar();//清除换行符
//	getnchar(input,n);
//	puts("输出读取的n个字符");
//	puts(input);
//	puts("输出读取的n个字符之后的字符，到遇到的第一个空格、制表符、换行符为止");
//	puts(input + n + 1);
//	return 0;
//}
//
//void getnchar(char * str,int num)
//{
//	int i;
//	int n;
//
//	for(i = 0;i < num;i++)
//	{
//		*(str + i) = getchar();
//	}
//	*(str + i) = '\0';
//	for(n = num + 1;n < SIZE;n++)
//	{
//		*(str + n) = getchar();
//		if(isspace(*(str + n)))//isblank(*(str + n))
//		{
//			break;
//		}
//	}
//	*(str + n) = '\0';
//}