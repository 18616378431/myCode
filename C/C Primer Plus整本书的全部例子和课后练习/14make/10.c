////函数指针
//#include<stdio.h>
//#include<ctype.h>
//#include<math.h>
//#define LEN 40
//
//void delMore(void);
//void ToUpper(char *);
//void ToLower(char *);
//void getAlphaNum(char *);
//void show(char *);
//void opera(void (*pf)(char *),char*);
//
//int main()
//{
//	//指向一个返回值为void，参数类型为char * 的函数指针
//	void (*pfun[3])(char *) = {ToUpper,ToLower,getAlphaNum};	
//	char ch;
//	char string[LEN] = "Hello!What is your name?";
//
//	puts("Type in your choice:");
//	while((ch = getchar()) != 'q')
//	{
//		switch(ch)
//		{
//		case 'a':
//			opera(pfun[0],string);
//			break;
//		case 'b':
//			opera(pfun[1],string);
//			break;
//		case 'c':
//			opera(pfun[2],string);
//			break;
//		default:
//			puts("Please type in an character such as a,b or c:");
//			break;
//		}
//		show(string);
//		delMore();
//		puts("Type in your choice:");
//	}
//	return 0;
//}
////清除换行
//void delMore()
//{
//	while(getchar() != '\n')
//		continue;
//}
////转大写
//void ToUpper(char * str)
//{
//	puts("toupper:");
//	while(*str != '\0')
//	{
//		*str = toupper(*str);
//		str++;
//	}
//}
////转小写
//void ToLower(char * str)
//{
//	puts("tolower:");
//	while(*str != '\0')
//	{
//		*str = tolower(*str);
//		str++;
//	}
//}
////字母个数
//void getAlphaNum(char * str)
//{
//	int ct = 0;
//
//	while(*str != '\0')
//	{
//		if(isalpha(*str))
//		{
//			ct++;
//		}
//		str++;
//	}
//	printf("There is %d characters.\n",ct);
//}
////显示函数执行结果
//void show(char * str)
//{
//	puts(str);
//}
////执行函数
//void opera(void (*pf)(char *),char * str)
//{
//	(*pf)(str);
//}