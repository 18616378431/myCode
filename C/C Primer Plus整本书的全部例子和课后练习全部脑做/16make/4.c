//clock()��������time.h�ж���,ԭ��:clock_t clock(void);���ش�����ʱ�䣬�޷��õ�����-1
//time.h�����CLOCKS_PER_SECΪÿ��Ĵ�����ʱ�䵥λ����
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