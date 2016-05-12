//命令行程序,参数
//-p原样输出
//-u大写输出
//-l小写输出
//#include<stdio.h>
//#include<ctype.h>
//#define SIZE 81
//
//int main(int argc,char * argv[])
//{
//	char ch;
//
//	if(argv[1][0] == '-')
//	{
//		if(argv[1][1] == 'p')//原样输出
//		{
//			while((ch = getchar()) != EOF)
//			{
//				putchar(ch);
//			}
//		}
//		else if(argv[1][1] == 'u')//大写输出
//		{
//			while((ch = getchar()) != EOF)
//			{
//				putchar(toupper(ch));
//			}
//		}
//		else if(argv[1][1] == 'l')//小写输出
//		{
//			while((ch = getchar()) != EOF)
//			{
//				putchar(tolower(ch));
//			}
//		}
//	}
//	return 0;
//}