////冒泡排序，数组最大值和最小值差
//#include<stdio.h>
//
//void showSub(double ar[],int n);
//
//int main()
//{
//	double source[] = {1.1,22.2,130.3,9.9,8.8,5.5};
//
//	showSub(source,6);
//	printf("The sub between max and min in array is : %.2lf.\n",source[5] - source[0]);
//	return 0;
//}
////数组冒泡排序
//void showSub(double ar[],int n)
//{
//
//	  int i, j;
//	  double t;
//  
//    for(i = 0;i < n - 1;i++)
//	{
//		for(j = i + 1;j < n;j++)
//		{
//			//printf("%.2lf  %.2lf\n",ar[i],ar[j]);
//			if(ar[i] > ar[j])
//			{
//				t = ar[i];
//				ar[i] = ar[j];
//				ar[j] = t;
//			}
//		}
//	}
//	for(i = 0;i < n;i++)
//	{
//		printf("ar %d = %.2lf\n",i,ar[i]);
//	}
//}