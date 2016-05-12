////从输入读取n个字符，包括空格，制表符，换行
//#include<stdio.h>
//#define LEN 10
//
//char * getnchar(char * str,int n);
//
//int main()
//{
//	char input[LEN];
//	char * chk;//存储读取输入函数的返回值
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