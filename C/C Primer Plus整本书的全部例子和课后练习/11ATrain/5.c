//ÔÚ×Ö·û´®ÖÐËÑË÷×Ö·û
//#include<stdio.h>
//
//char *is_within(char * str,char ch);
//
//int main()
//{
//	char name[81];
//	char ch;
//	char * p;
//
//	do
//	{
//		puts("name:");
//		gets(name);
//		puts("ch:");
//		ch = getchar();
//		getchar();//Çå³ý»»ÐÐ·û
//		p = is_within(name,ch);
//		if(p)
//		{
//			puts("Find it!");
//			putchar(*p);
//			putchar('\n');
//		}
//		else
//		{
//			puts("Can't find!");
//			puts("Input a character except q to go on!");
//			gets(name);
//		}
//	}while(*name != 'q');
//	return 0;
//}
////ÔÚ×Ö·û´®ÖÐËÑË÷×Ö·û
//char *is_within(char * str,char ch)
//{
//	char * pt = str;
//	
//	while(*pt != ch)
//	{
//		pt++;
//		if(*pt == '\0')
//		{
//			return NULL;
//		}
//	}
//	return pt;
//}