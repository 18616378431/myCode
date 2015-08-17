////返回int数组的最大值
//#include<stdio.h>
//
//int showMax(int ar[],int size);
//
//int main()
//{
//	int arr[] = {1,31,9,100,4,3};
//	int maxarr;
//
//	maxarr = showMax(arr,6);
//	printf("max in arr is %d\n",maxarr);
//	return 0;
//}
//
//int showMax(int ar[],int size)
//{
//	int i;
//	int j;
//	int max = 0;
//
//	for(i = 0;i < size - 1;i++)
//	{
//		for(j = i + 1;j < size;j++)
//		{
//			//printf("%d %d\n",ar[i],ar[j]);
//			if(ar[i] > ar[j])
//			{
//				if(ar[i] > max)
//				{
//					max = ar[i];
//				}
//				else
//				{
//					continue;
//				}
//			}
//		}
//	}
//	return max;
//}