//#include<stdio.h>
//#include<ctype.h>
//#define SIZE 81
//
//void getnchar(char * str,int num);
//
//int main()
//{
//	char input[SIZE];
//	int n;//������ַ���
//
//	puts("Enter the number of your string:");
//	scanf("%d",&n);
//	getchar();//������з�
//	getnchar(input,n);
//	puts("�����ȡ��n���ַ�");
//	puts(input);
//	puts("�����ȡ��n���ַ�֮����ַ����������ĵ�һ���ո��Ʊ�������з�Ϊֹ");
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