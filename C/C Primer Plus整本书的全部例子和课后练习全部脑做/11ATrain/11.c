//��ȡ����ֱ��EOF,���浥��������д��ĸ����Сд��ĸ�������������������ַ���
//#include<stdio.h>
//#include<ctype.h>//isalpha(),isupper(),islower(),ispunct(),isdigit()
//#define SIZE 81
//
//int main()
//{
//	char str[SIZE];
//	char *p = str;
//	int wordNum = 0;
//	int upperNum = 0;
//	int lowerNum = 0;
//	int punctNum = 0;
//	int digitNum = 0;
//	int flag = 0;
//
//	puts("Enter your string:");
//	gets(str);
//	while(*p != '\0')
//	{
//		if(isalpha(*p))
//		{
//			if(flag == 0)
//			{
//				wordNum++;
//				flag = 1;
//			}
//		}
//		else
//		{
//			flag = 0;
//		}
//		if(isupper(*p))
//			upperNum++;
//		if(islower(*p))
//			lowerNum++;
//		if(ispunct(*p))
//			punctNum++;
//		if(isdigit(*p))
//			digitNum++;
//		p++;
//	}
//	printf("����:%d,��д��ĸ:%d,Сд��ĸ:%d,������:%d,�����ַ�:%d.\n",wordNum,upperNum,lowerNum,punctNum,digitNum);
//	return 0;
//}

//int main(void) 
//{
//	int word=0,upper=0,lower=0,punct=0,digit=0,begin=0; 
//	char ch;
//
//	while( ( ch = getchar() ) != EOF && ch != 'q') 
//	{
//		if( isalpha(ch) ) 
//		{
//			if (begin == 0) 
//			{
//				word++;
//				begin = 1; 
//			}
//		}
//		else 
//		{
//			begin = 0;
//		}
//		if( isupper(ch) ) upper++; 
//		if( islower(ch) ) lower++; 
//		if( ispunct(ch) ) punct++; 
//		if( isdigit(ch) ) digit++;
//	}
//	printf("word:%d\nupper:%d\nlower:%d\npunct:%d\ndigit:%d\n",word,upper,lower,punct,digit); 
//	return 0;
//}