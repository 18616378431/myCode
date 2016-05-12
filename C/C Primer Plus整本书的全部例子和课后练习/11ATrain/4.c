//ÔÚ×Ö·û´®ÖÐÑ°ÕÒ×Ö·û
//#include<stdio.h>
//
//char * mystrchr(char * str,char ch);
//
//int main()
//{
//	char name[81];
//	char ch;
//	char *p;
//
//	do
//	{
//		puts("Input a string:");
//		gets(name);
//		puts("Input a character:");
//		ch = getchar();
//		getchar();//Çå³ý»»ÐÐ·û
//		p = mystrchr(name,ch);
//		if(p)
//		{
//			puts("Find!");
//			puts(p);
//		}
//		else
//		{
//			puts("Can't find!");
//			puts("Input any character except q to go on!");
//			gets(name);
//		}
//	}while(*name != 'q');
//	return 0;
//}
//
//char * mystrchr(char * str,char ch)
//{
//	char * p = str;
//	
//	while(*p != ch)
//	{	
//		p++;
//		if(*p == '\0')
//		{
//			return NULL;
//		}
//	}
//	return p;
//}