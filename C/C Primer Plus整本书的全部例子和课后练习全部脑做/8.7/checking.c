//#include<stdio.h>
//#define bool int
//#define TRUE 1
//#define FALSE 0
//#define MAX +1000		//范围的上界
//#define MIN -1000		//范围的下界
//
////函数声明
//int get_int(void);
//bool bad_limits(int begin,int end,int low,int high);
//double sum_tp(int a,int b);
//
//int main(void)
//{
//	int start;		//下界
//	int stop;		//上界
//	double answer;		//下界到上界之间的平方和
//
//	printf("This processer will process the square between start and stop.\n");
//	printf("Enter 0 for both lower and upper to quit.\n");
//	printf("Enter start and stop:\n");
//	printf("Lower limit:");
//	start = get_int();
//	printf("Upper limit:");
//	stop = get_int();
//	while(start != 0 || stop != 0)
//	{
//		if(bad_limits(start,stop,MIN,MAX))
//		{
//			printf("Please try again.\n");
//		}
//		else
//		{
//			answer = sum_tp(start,stop);
//			printf("The sum of the squares of the integers from");
//			printf(" %d to %d is %g.\n",start,stop,answer);
//		}
//		printf("Enter 0 for both lower and upper to quit.\n");
//		printf("Lower limit:");
//		start = get_int();
//		printf("Upper limit:");
//		stop = get_int();
//	}
//	printf("Done.\n");
//	return 0;
//}
//
////获取整数并提示
//int get_int(void)
//{
//	int input;		//获取输入值
//	char ch;		//存储错误字符
//
//	while(scanf("%d",&input) != 1)
//	{
//		while((ch = getchar()) != '\n')
//		{
//			putchar(ch);
//		}
//		printf(" is not an integer.\n");
//		printf("Please type in some value like 3,-5,12 or 178.\n");
//	}
//	return input;
//}
//
////确认下界上界的数值是否有效
//bool bad_limits(int begin,int end,int low,int high)
//{
//	bool not_good = FALSE;
//	if(begin > end)
//	{
//		printf("%d isn't smaller than %d.\n",begin,end);
//		not_good = TRUE;
//	}
//	if(begin < low || end < low)
//	{
//		printf("value must be %d or greater.\n",low);
//		not_good = TRUE;
//	}
//	if(begin > high || end > high)
//	{
//		printf("value must be %d or less.\n",high);
//		not_good = TRUE;
//	}
//	return not_good;
//}
//
////计算start到stop的平方和
//double sum_tp(int a,int b)
//{
//	double stotal = 0.00;
//	int i;
//
//	for(i = a;i <= b;i++)
//	{
//		stotal += i * i;
//	}
//	return stotal;
//}