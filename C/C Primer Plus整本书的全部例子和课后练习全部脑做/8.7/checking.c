//#include<stdio.h>
//#define bool int
//#define TRUE 1
//#define FALSE 0
//#define MAX +1000		//��Χ���Ͻ�
//#define MIN -1000		//��Χ���½�
//
////��������
//int get_int(void);
//bool bad_limits(int begin,int end,int low,int high);
//double sum_tp(int a,int b);
//
//int main(void)
//{
//	int start;		//�½�
//	int stop;		//�Ͻ�
//	double answer;		//�½絽�Ͻ�֮���ƽ����
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
////��ȡ��������ʾ
//int get_int(void)
//{
//	int input;		//��ȡ����ֵ
//	char ch;		//�洢�����ַ�
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
////ȷ���½��Ͻ����ֵ�Ƿ���Ч
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
////����start��stop��ƽ����
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