//#include<stdio.h>
//#include<ctype.h>		//提供ispunct()函数原型
//
//int main(void)
//{
//	char ch;
//	int count = 0;		//单词个数
//	int len = 0;		//每个单词的字母个数
//	int totlen = 0;		//所有单词的字母个数
//	float ave;
//
//	while((ch = getchar()) != EOF)
//	{
//		if(ispunct(ch) || isspace(ch))
//		{
//			count++;	
//			totlen += len;
//			len = 0;
//			if(ch != '\n')
//			{
//				continue;	
//			}
//			else
//			{
//				break;
//			}	
//		}
//		len++;
//	}
//	ave = (float)totlen/count;
//	printf("字母总数:%d,单词个数:%d,每个单词平均字母数:%.2f\n",totlen,count,ave);
//	return 0;
//}