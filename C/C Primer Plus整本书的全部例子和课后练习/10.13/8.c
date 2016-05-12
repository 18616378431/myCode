//#include<stdio.h>
//
//void copy_2d(double ar[][5],double tar[][5],int n);
//void show_2d(double ar[][5],double tar[][5],int n);
//
//int main()
//{
//	double source[3][5] = {
//		{ 1.1, 2.2, 3.3, 4.4, 5.5},
//		{11.1,12.2,13.3,14.4,15.5},
//		{21.1,22.2,23.3,24.4,25.5}
//	};
//	double target[3][5];
//
//	copy_2d(source,target,3);
//	show_2d(source,target,3);
//	return 0;
//}
////变长数组声明void copy_2d(int r,int c,double ar[r][c],double tar[r][c])
//void copy_2d(double ar[][5],double tar[][5],int n)
//{
//	int r;
//	int c;
//
//	for(r = 0;r < n;r++)
//	{
//		for(c = 0;c < 5;c++)
//		{
//			tar[r][c] = ar[r][c];
//		}
//	}
//}
////变长数组声明void show_2d(int r,int c,double ar[r][c],double tar[r][c])
//void show_2d(double ar[][5],double tar[][5],int n)
//{
//	int r;
//	int c;
//	for(r = 0;r < n;r++)
//	{
//		for(c = 0;c < n;c++)
//		{
//			printf("source[%d][%d] = %.2lf\n",r,c,ar[r][c]);
//		}
//	}
//
//	for(r = 0;r < n;r++)
//	{
//		for(c = 0;c < n;c++)
//		{
//			printf("target[%d][%d] = %.2lf\n",r,c,tar[r][c]);
//		}
//	}
//}