////接收两个字符串指针参数
////如果第二个字符串包含在第一个字符串中
////则返回被包含字符串在字符串中的开始地址
////否则返回空指针
////strstr(),在字符串中查找字符串
//#include<stdio.h>
//#include<string.h>
//#define SIZE 81
//
//char * string_in(char * s1,char * s2);
//
//int main()
//{
//	char s1[SIZE];
//	char s2[SIZE];
//	char * p;
//
//	do
//	{
//		puts("Input a string for s1:");
//		gets(s1);
//		puts("Input a string for s2:");
//		gets(s2);
//		p = string_in(s1,s2);
//		if(p)
//		{
//			puts(p);
//		}
//		else
//		{
//			puts("Can't find it!");
//			puts("Input a character except q to go on:");
//			gets(s1);
//		}
//	}while(*s1 != 'q');
//	return 0;
//}
//
//char * string_in(char * s1,char * s2)
//{
//	char * p1 = s1;
//	char * p2 = s2;
//	
//	if(*p1 == '\0' || *p2 == '\0')
//	{
//		return NULL;
//	}
//	while(1)
//	{
//		if(*p1 == *p2)
//		{
//			if(*++p2 == '\0')//如果s2到达末尾，返回p1
//			{
//				return p1 - (strlen(s2) - 1);
//			}
//			if(*++p1 == '\0')//如果s2没有到达末尾，s1先到达末尾，返回空指针
//			{
//				return NULL;
//			}
//		}
//		else
//		{
//			if(*++p1 == '\0')
//			{
//				return NULL;
//			}
//			p2 = s2;
//		}
//	}
//}