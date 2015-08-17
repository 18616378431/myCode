////编写产生100从1到10的范围随机数的程序并以降序排列
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define NUM 100
//
//void get_num(int *p,int n);
//void grade_down(int *pt,int m);
//void show_arr(int *a,int l);
//
//int main()
//{
//	int arr[NUM];
//
//	get_num(arr,NUM);
//	grade_down(arr,NUM);
//	show_arr(arr,NUM);
//	return 0;
//}
////产生100随机数存储到数组中
//void get_num(int *p,int n)
//{
//	int i;
//	
//	srand((unsigned int)time(NULL));
//	for(i = 0;i < n;i++)
//	{
//		p[i] = rand()%10 + 1;
//	}
//}
////降序排列
//void grade_down(int *pt,int m)
//{
//	int top;
//	int seek;
//	int temp;
//
//	for(top = 0;top < m - 1;top++)
//	{
//		for(seek = top + 1;seek < m;seek++)
//		{
//			if(pt[top] < pt[seek])
//			{
//				temp = pt[top];
//				pt[top] = pt[seek];
//				pt[seek] = temp;
//			}
//		}
//	}
//}
////输出数组
//void show_arr(int *a,int l)
//{
//	int i;
//
//	for(i = 0;i < l;i++)
//	{
//		printf("%5d ",a[i]);
//		if(i % 7 == 0 && i != 0)
//		{
//			putchar('\n');
//		}
//	}
//	putchar('\n');
//}