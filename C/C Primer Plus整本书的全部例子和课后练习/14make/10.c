////����ָ��
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
//	//ָ��һ������ֵΪvoid����������Ϊchar * �ĺ���ָ��
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
////�������
//void delMore()
//{
//	while(getchar() != '\n')
//		continue;
//}
////ת��д
//void ToUpper(char * str)
//{
//	puts("toupper:");
//	while(*str != '\0')
//	{
//		*str = toupper(*str);
//		str++;
//	}
//}
////תСд
//void ToLower(char * str)
//{
//	puts("tolower:");
//	while(*str != '\0')
//	{
//		*str = tolower(*str);
//		str++;
//	}
//}
////��ĸ����
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
////��ʾ����ִ�н��
//void show(char * str)
//{
//	puts(str);
//}
////ִ�к���
//void opera(void (*pf)(char *),char * str)
//{
//	(*pf)(str);
//}