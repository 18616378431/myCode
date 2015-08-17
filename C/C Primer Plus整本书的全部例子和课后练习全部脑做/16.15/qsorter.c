//对随机浮点数数组按从小到大排序
#include<stdio.h>
#include<stdlib.h>

#define NUM 40

int myCompar(const void * p1,const void * p2);
void fillArr(double arr[],int n);
void showArr(double arr[],int n);

int main()
{
	double vals[NUM];

	fillArr(vals,NUM);
	puts("Random list:");
	showArr(vals,NUM);
	qsort(vals,NUM,sizeof(double),myCompar);
	puts("Sorted list:");
	showArr(vals,NUM);
	return 0;
}
//为数组元素赋值
void fillArr(double arr[],int n)
{
	int index;

	for(index = 0;index < n;index++)
	{
		arr[index] = (double)rand() / ((double)rand() + 0.1);
	}
}
//显示数组元素
void showArr(double arr[],int n)
{
	int index = 0;

	while(index < n)
	{
		printf("%9.4f",arr[index]);
		if(++index % 6 == 0)
			putchar('\n');
	}
	if(index % 6 != 0)
		putchar('\n');
}
int myCompar(const void * p1,const void * p2)
{
	//将接收的指针类型转换为对应数组元素类型的指针
	const double * a1 = (const double *)p1;
	const double * a2 = (const double *)p2;

	if(*a1 < *a2)//从小到大
		return -1;
	else if(*a1 == *a2)
		return 0;
	else
		return 1;
}