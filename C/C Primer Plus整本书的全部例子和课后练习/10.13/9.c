//#include<stdio.h>
//
//void getSum(int ar1[],int ar2[],int sum[],int n);
//void showSum(int sum[],int n);
//
//int main()
//{
//	int ar1[] = {2,4,5,8};
//	int ar2[] = {1,0,4,6};
//	int sum[4];
//	int n = sizeof(ar1) / sizeof(int);
//
//	getSum(ar1,ar2,sum,n);
//	showSum(sum,n);
//	return 0;
//}
//
//void getSum(int ar1[],int ar2[],int sum[],int n)
//{
//	int i;
//
//	for(i = 0;i < n;i++)
//	{
//		sum[i] = ar1[i] + ar2[i];
//	}
//}
//
//void showSum(int sum[],int n)
//{
//	int i;
//	
//	for(i = 0;i < n;i++)
//	{
//		printf("sum[%d] = %d\n",i,sum[i]);
//	}
//}