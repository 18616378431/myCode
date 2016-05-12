////重做复习题3，用月份拼写代替月份号
//#include<stdio.h>
//#include<string.h>//strcmp()
//#include<ctype.h>//tolower()
//#define LENGTH 41
//#define LEN 21
//#define true 1
//#define false 0
//#define BOOL int
//
//typedef struct month{
//	char name[LENGTH];
//	char abbrev[LEN];
//	int days;
//	int monthNum;
//} MONTH;
//MONTH mon[12] = {
//		{"January","jan",31,1},
//		{"February","feb",28,2},
//		{"March","mar",31,3},
//		{"April","apr",30,4},
//		{"May","may",31,5},
//		{"June","jun",30,6},
//		{"July","jul",31,7},
//		{"August","aug",31,8},
//		{"September","sep",30,9},
//		{"October","oct",31,10},
//		{"November","nov",30,11},
//		{"December","dec",31,12},
//	};
//
//void getDays(struct month * p);
//void ToLower(char * str);
//
//int main()
//{
//	MONTH * ps = mon;
//	getDays(ps);
//	return 0;
//}
//void getDays(MONTH * p)
//{
//	MONTH * begin = p;
//	int year;
//	int month;
//	int day;
//	int totalDays = 0;
//	BOOL isFound = false;
//	int i;
//
//	puts("Enter year month day:");
//	while(scanf("%d %d %d",&year,&month,&day) == 3)
//	{
//		if(month < 1 || month > 12)
//		{
//			puts("Error month,enter next");
//			continue;
//		}
//		for(i = 0;i < 12;i++)
//		{
//			if(month == p->monthNum)
//			{
//				if(day <= p->days)
//				{
//					isFound = true;
//				}
//				else
//				{
//					puts("Error month days!");
//					
//				}
//				break;
//			}
//			totalDays += p->days;
//			p++;
//		}
//		totalDays += day;
//		if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
//		{
//			if(month > 2)
//			{
//				totalDays++;
//			}
//		}
//		if(isFound)
//			printf("There is %d days\n",totalDays);
//		else
//			puts("Error month name");
//		totalDays = 0;
//		p = begin;
//	}
//}
//void ToLower(char * str)
//{
//	while(*str != '\0')
//	{
//		*str = tolower(*str);
//		str++;
//	}
//}