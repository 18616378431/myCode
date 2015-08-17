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
//int getDays(struct month * p);
//void ToLower(char * str);
//
//int main()
//{
//	MONTH * ps = mon;
//	getDays(ps);
//	return 0;
//}
//int getDays(struct month * p)
//{
//	char mname[LENGTH];
//	int i;
//	int totalDays = 0;
//	BOOL isFound = false;
//
//	puts("Enter month name:");
//	scanf("%s",&mname);
//	ToLower(mname);
//	for(i = 0;i < 12;i++)
//	{
//		ToLower(p->name);
//		totalDays += p->days;
//		if(strcmp(p->name,mname) == 0)
//		{
//			isFound = true;
//			break;
//		}
//		p++;
//	}
//	if(isFound)
//		printf("There is %d days before month %s.\n",totalDays,mname);
//	else
//		puts("Error month name");
//	return totalDays;
//}
//void ToLower(char * str)
//{
//	while(*str != '\0')
//	{
//		*str = tolower(*str);
//		str++;
//	}
//}