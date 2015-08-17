//#include<stdio.h>
//#include"pe12-2a.h"
//
//void set_mode(int m)
//{
//	if(m > 1)
//	{
//		printf("Invalid mode specified.US mode used.\n");
//		mode = 1;
//	}
//	else
//	{
//		mode = m;
//	}
//}
//
//void get_info()
//{
//	extern int distance;
//	if(mode == 0)
//	{
//		printf("Enter distance traveled in kilometers:");
//		scanf("%d",&distance);
//		printf("Enter fuel consumed int liters:");
//		scanf("%lf",&oil);
//	}
//	else if(mode == 1)
//	{
//		printf("Enter distance traveled int miles:");
//		scanf("%d",&distance);
//		printf("Enter fuel consumed int gallons:");
//		scanf("%lf",&oil);
//	}
//}
//
//void show_info()
//{
//	if(mode == 0)
//	{
//		printf("Fuel consumption is %.2lf liters per 100km.\n",(oil * 100)/distance);
//	}
//	else if(mode == 1)
//	{
//		printf("Fuel consumption is %.1lf miles per gallon.\n",distance/oil);
//	}
//}