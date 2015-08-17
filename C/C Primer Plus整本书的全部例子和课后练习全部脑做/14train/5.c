//#include<stdio.h>
//#include<string.h>//strcpy()
//#define LENGTH 41
//#define LEN 4
//
//struct month{
//	char name[LENGTH];
//	char abbrev[LEN];
//	int days;
//	int monthNum;
//};
//typedef struct lens{
//	float foclen;
//	float fstop;
//	char brand[41];
//} LENS;
//struct name{
//	char first[41];
//	char last[41];
//};
//struct bem{
//	int limbs;
//	struct name title;
//	char type[40];
//};
//struct bem deb = {
//	6,
//	{"Berbnazel","Gwolkapwolk"},
//	"Arcturan"
//};
//int getDays(int monthNum,const struct month *p);
//void showS(struct bem * ps);
//
//int main()
//{
//	struct month mon[12] = {
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
//	struct month * ps = mon;
//	int monNum;
//	struct bem * pb = &deb;
//
//	LENS test[10];
//
//	test[2].foclen = 500;
//	test[2].fstop = 10/2.0;
//	strcpy(test[2].brand,"Remarkatar");
//
//	
//
//	/*puts("Enter month number:");
//	scanf("%d",&monNum);*/
//	monNum = 3;
//	printf("There is %d days from 1 to %d month.\n",getDays(monNum,ps),monNum);
//	showS(pb);
//	return 0;
//}
////返回一年中到当前月份的总天数(包含当前月份)
//int getDays(int monthNum,const struct month *p)
//{
//	int totalDays = 0;
//	int i = 0;
//
//	if(monthNum < 1 || monthNum > 12)
//	{
//		return -1;
//	}
//	while(i++ < monthNum)
//	{
//		totalDays += p++->days;
//	}
//	return totalDays;
//}
////以结构的地址为参数，输出结构内容
//void showS(struct bem * ps)
//{
//	printf("%s %s is a %d-limbed %s.\n",ps->title.first,ps->title.last,ps->limbs,ps->type);
//}