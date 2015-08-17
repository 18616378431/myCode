//#include<stdio.h>
//
//int main(void)
//{
//	char ch;
//	int i;
//	int count = 0;//Ìæ»»´ÎÊý
//
//	while((ch = getchar()) != '#')
//	{
//		if(ch == '!')
//		{
//			count++;
//			for(i=0;i<1;i++)
//			{
//				putchar(ch);
//			}
//		}
//		if(ch == '.')
//		{
//			count++;
//			ch = '!';
//		}
//		putchar(ch);
//	}
//	printf("replace times are %d.\n",count);
//	return 0;
//}