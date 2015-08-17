////一个接受三个参数的函数:参数一为已排序的整型数组，参数二为数组元素个数，参数三为要查找的项
////该数在数组中，返回true，否则返回false
//#include<stdio.h>
//#define MAX 20
//#define BOOL int
//#define true 1
//#define false 0
//
//void upList(int * arr);
//BOOL func(int * arr,int size,int goal);
//void show(int * arr,int size);
//
//int main()
//{
//	int arr[MAX] = {11,55,32,67,95,23,45,66,59,68,75,73,2,9,7,6,46,33,99,300};
//	int goal;
//	
//	puts("Enter goal:");
//	scanf("%d",&goal);
//	upList(arr);
//	show(arr,MAX - 1);
//	putchar('\n');
//	if(func(arr,MAX - 1,goal))
//		puts("Found!");
//	else
//		puts("Not found!");
//	return 0;
//}
////函数
//BOOL func(int * arr,int size,int goal)
//{
//	BOOL flag = false;
//	int start;
//	int end;
//	int i;
//	int ct = 0;
//
//	for(start = 0,end = size;start <= end;)
//	{
//		i = (start + end) / 2;
//		printf("%d次,arr[%d] = %d\n",++ct,i,arr[i]);
//		if(goal == arr[i])
//		{
//			flag = true;
//			break;
//		}
//		else if(goal > arr[i])
//		{
//			start = i + 1;
//		}
//		else if(goal < arr[i])
//		{
//			end = i - 1;
//		}
//	}
//	return flag;
//}
////一维数组冒泡排序
//void upList(int * arr)
//{
//	int i,j;
//	int temp;
//
//	for(i = 0;i < MAX - 1;i++)
//	{
//		for(j = i + 1;j < MAX;j++)
//		{
//			if(arr[i] > arr[j])
//			{
//				temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//}
////show
//void show(int * arr,int size)
//{
//	if(size >= 0)
//	{
//		printf("%3d",arr[size]);
//		show(arr,size - 1);
//	}
//}