////数组最大值下标
//#include<stdio.h>
//
//int showBI(double ar[],int n);
//
//int main()
//{
//	double source[] = {1.1,22.2,3.3,9.9,8.8,5.5};
//
//	printf("The max's index is %d\n",showBI(source,6));
//	return 0;
//}
//
//int showBI(double ar[],int n)
//{
//	int index =0;
//	int i;
//	int j;
//	double max = 0;
//
//	for(i = 0;i < n -1;i++)
//	{
//		for(j = i + 1;j < n;j++)
//		{
//			printf("%.1lf %.1lf \n",ar[i],ar[j]);
//			if((ar[i] - ar[j]) > 0)
//			{
//				if((ar[i] - max) > 0)
//				{
//					max = ar[i];
//					index = i;
//				}
//				else
//				{
//					continue;
//				}
//			}
//		}
//	}
//	return index;
//}