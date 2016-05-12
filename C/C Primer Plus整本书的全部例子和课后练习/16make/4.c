//clock()函数，在time.h中定义,原型:clock_t clock(void);返回处理器时间，无法得到返回-1
//time.h定义的CLOCKS_PER_SEC为每秒的处理器时间单位个数
//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//#include<windows.h>
//
//void getTime();
//
//int main()
//{
//	int t;
//	double c1;
//	double c2;
//
//	puts("Enter an delay time number:");
//	scanf("%d",&t);
//	c1 = clock();
//	getTime();
//	Sleep(t);
//	getTime();
//	c2 = clock();
//	printf("The time is %lfs.\n",(c2 - c1) / CLOCKS_PER_SEC);
//	return 0;
//}
//void getTime()
//{
//	time_t rawtime;
//	struct tm * timeinfo;
//
//	time(&rawtime);
//	timeinfo = localtime(&rawtime);
//	printf("%s",asctime(timeinfo));
//}