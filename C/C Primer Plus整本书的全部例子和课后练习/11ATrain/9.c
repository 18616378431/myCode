////删除字符串中的空格
//#include<stdio.h>
//#include<ctype.h>
//#define SIZE 81
//
//void remove_blank(char * s);
//
//int main()
//{
//	char str[SIZE];
//
//	do
//	{
//		
//		puts("Enter str(q to quit):");
//		gets(str);
//		remove_blank(str);
//		puts(str);
//		puts("inpu any char except q to go on.");
//		gets(str);
//	}while(*str != 'q');
//	return 0;
//}
//
//void remove_blank(char * s)
//{
//	char * p;
//
//	while(*s != '\0')
//	{
//		if(*s == ' ')
//		{
//			p = s;
//			while(*p != '\0')
//			{
//				*p = *(p + 1);
//				p++;
//			}
//		}
//		else
//		{
//			s++;
//		}
//		
//	}
//}
//
////while (*s != '\0' ) 
////{
////	if (*s == ' ') 
////	{
////		p = s; 
////		while(*p != '\0') 
////		{
////			*p = *(p+1);
////			p++; 
////		}
////		s--; //抵消下面的 s++ 
////	}
////	s++; 
////}
