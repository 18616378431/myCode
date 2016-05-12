//#include<stdio.h>
//
//char *pr(char * str);
//
//int main()
//{
//	char * name = "Hello World!";
//	char * pt;
//
//	pt = pr(name);
//	if(pt != NULL)
//	{
//		puts(pt++);
//	}
//	else
//	{
//		puts("NULL Pointer!");
//	}
//	return 0;
//}
//
//char *pr(char * str)
//{
//	char * ptr;
//	ptr = str;
//
//	while(*ptr)
//	{
//		if(*ptr == ' ')
//		{
//			str = ptr;
//			break;
//		}
//		else
//		{
//			ptr++;
//		}
//	}
//	if(*ptr == '\0')
//	{
//		str = NULL;
//	}
//	return str;
//}