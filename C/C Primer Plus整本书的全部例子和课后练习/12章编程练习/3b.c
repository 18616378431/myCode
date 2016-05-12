//#include<stdio.h>
//#include"3.h"
//
//void set_mode(int n)
//{
//	if(n > 1)
//	{
//		printf("Invalid mode specified.Mode 1(US) used.\n");
//		n = 1;
//	}
//	get_info(n);
//}
//
//void get_info(int m)
//{
//	double oil;
//	int distance;
//
//	if(m == 0)
//	{
//		printf("Enter distance traveled in kilometers:");
//		scanf("%d",&distance);
//		printf("Enter fuel consumed in liters:");
//		scanf("%lf",&oil);
//	}
//	else if(m == 1)
//	{
//		printf("Enter distance traveled in miles:");
//		scanf("%d",&distance);
//		printf("Enter fuel consumed in gallons:");
//		scanf("%lf",&oil);
//	}
//	show_info(m,oil,distance);
//}
//
//void show_info(int mode,double oil,int distance)
//{
//	if(mode == 0)
//	{
//		printf("Fuel consumption is %.2f liters per 100km.\n",oil*100/distance);
//	}
//	else if(mode == 1)
//	{
//		printf("Fuel consumption is %.1f miles per gallons.\n",distance/oil);
//	}
//}