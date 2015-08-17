////复制字符串strncat()
//#include<stdio.h>
//#include<string.h>
//#define MAX 30
//#define SIZE 15
//
//char *mystrncpy(char * s1,char * s2,int n);
//char *mystrncpy1(char *p1,char *p2,int n);
//
//int main()
//{
//	char s1[MAX];
//	char s2[SIZE];
//	int n;
//	char *p;
//
//	do
//	{
//		puts("Input string s1:");
//		gets(s1);
//		puts("Input string s2:");
//		gets(s2);
//		puts("Input the number of characters you want to copy:");
//		scanf("%d",&n);
//		getchar();//清除换行符
//		p = mystrncpy(s1,s2,n);
//		if(p)
//		{
//			puts("Success!");
//			puts(p);
//		}
//		else
//		{
//			puts("Failed!");
//			puts("Input a character except q to go on:");
//			puts("Input string s1:");
//			gets(s1);
//			puts("Input string s2:");
//			gets(s2);
//			puts("Input the number of characters you want to copy:");
//			scanf("%d",&n);
//		}
//	}while(*s1 != 'q' && *s2 != 'q');
//	return 0;
//}
//
//char *mystrncpy(char * s1,char * s2,int n)
//{
//	//找到s1的末尾空字符位置，将s2首地址赋给空字符位置
//	int i = 0;
//	int k;//计数s2字符位置
//	char *p1 = s1;
//	char *p2 = s2;
//	//计算s1字符数并且移动指针到末尾
//	while(*p1 != '\0')
//	{
//		i++;
//		p1++;
//	}
//	for(k = 0;k < n;k++)
//	{
//		*p1 = p2[k];
//		p1++;
//	}
//	s1[i + n] = '\0';
//	return s1;
//}
//
//char *mystrncpy1(char *p1,char *p2,int n)
//{
//	char *p = p1;
//	//将指针移动到s1末尾
//	while(*p1++ != '\0')
//		continue;
//	*--p1 = *++p2;
//	n--;
//	while(n > 0 && *p2 != '\0')
//	{
//		*++p1 = *++p2;
//		n--;
//	}
//	return p;
//}