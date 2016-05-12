//#include<stdio.h>
//
//void copy_arr(double ar[],double tar[],int size);
//void copy_ptr(double * ar,double * tar,int size);
//
//int main()
//{
//	double source[5] = {1.1,2.2,3.3,4.4,5.5};
//	double target1[5];
//	double target2[5];
//
//	copy_arr(source,target1,5);
//	putchar('\n');
//	copy_ptr(source,target2,5);
//	return 0;
//}
//
//void copy_arr(double ar[],double tar[],int size)
//{
//	int r;
//	
//	//copy数组
//	for(r = 0;r < size;r++)
//	{
//		tar[r] = ar[r];
//	}
//	//显示新数组
//	for(r = 0;r < size;r++)
//	{
//		printf("target1 %d = %.2lf\n",r + 1,tar[r]);
//	}
//}
//
//void copy_ptr(double * ar,double * tar,int size)
//{
//	int r;
//	//copy数组
//	for(r = 0;r < size;r++)
//	{
//		*(tar + r) = *(ar + r);
//	}
//	//显示新数组
//	for(r = 0;r < size;r++)
//	{
//		printf("target2 %d = %.2lf\n",r + 1,*(tar + r));
//	}
//}