////反向输出字符串
//#include<stdio.h>
//#include<string.h>
//#define SIZE 81
//
////void againstWord(char * s1,char * s2);
//
//void reverse(char * p);
//
//
////int main()
////{
////	char str1[SIZE];
////	char str2[SIZE];
////
////	do
////	{
////		puts("Enter str1(q to quit):");
////		gets(str1);
////		againstWord(str1,str2);
////		puts("反向排序后");
////		puts(str2);
////		printf("s1 = %d\n",strlen(str1));
////	}while(*str1 != 'q');
////	return 0;
////}
////
////void againstWord(char * s1,char * s2)
////{
////	char * p1 = (s1 + (strlen(s1) - 1));
////	char * p2 = s2;
////	int i;
////
////	for(i = 0;i < (int)strlen(s1);i++)
////	{
////		*p2++ = (*p1--);
////	}
////	
////}
//
//int main()
//{
//	char str[81];
//
//	puts("Enter str:");
//	gets(str);
//
//	reverse(str);
//	puts(str);
//	return 0;
//}
//
//void reverse(char * p)
//{
//	int i,n;
//	char temp;
//
//	//for(n = 0;*(p + n) != '\0';n++)//计算字符串长度值n
//	//{
//	//	continue;
//	//}
//	//n--;
//	n = (int)strlen(p) - 1;
//	for(i = 0;i < n - i;i++)
//	{
//		temp = p[i];
//		p[i] = p[n - i];
//		p[n - i] = temp;
//	}
//}