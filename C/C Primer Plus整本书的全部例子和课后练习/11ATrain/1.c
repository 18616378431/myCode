////�������ȡn���ַ��������ո��Ʊ��������
//#include<stdio.h>
//#define LEN 10
//
//char * getnchar(char * str,int n);
//
//int main()
//{
//	char input[LEN];
//	char * chk;//�洢��ȡ���뺯���ķ���ֵ
//
//	chk = getnchar(input,LEN - 1);
//	if(chk == NULL)
//		puts("Input failed!");
//	else
//		puts(input);
//	puts("Done!");
//	return 0;
//}
//
//char * getnchar(char * str,int n)
//{
//	int i;
//	int ch;
//
//	for(i = 0;i < n;i++)
//	{
//		ch = getchar();
//		if(ch != EOF)
//			str[i] = ch;
//		else
//			break;
//	}
//	if(ch == EOF)
//		return NULL;
//	else
//		str[i] = '\0';
//		return str;
//}