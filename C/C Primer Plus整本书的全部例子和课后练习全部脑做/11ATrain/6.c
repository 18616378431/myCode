////�����ַ���strncat()
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
//		getchar();//������з�
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
//	//�ҵ�s1��ĩβ���ַ�λ�ã���s2�׵�ַ�������ַ�λ��
//	int i = 0;
//	int k;//����s2�ַ�λ��
//	char *p1 = s1;
//	char *p2 = s2;
//	//����s1�ַ��������ƶ�ָ�뵽ĩβ
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
//	//��ָ���ƶ���s1ĩβ
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