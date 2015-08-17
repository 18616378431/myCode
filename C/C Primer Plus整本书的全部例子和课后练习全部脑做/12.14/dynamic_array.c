//为数组动态分配存储空间
#include<stdio.h>
#include<stdlib.h>//malloc(),free()提供原型

int main()
{
	double * ptd;//指向分配的内存块首地址
	int max;
	int number;
	int i = 0;
	//获取程序需要的元素最大个数
	printf("What is the maximum number of type double entries?\n");
	scanf("%d",&max);
	//为程序动态分配内存空间并创建数组
	ptd = (double *)malloc(max * sizeof(double));//请求一个max个double值大小的内存块,并将首地址赋给ptd
	if(ptd == NULL)//内存分配失败，程序异常终止
	{
		printf("Memory allocation failed.Goodbye!\n");
		exit(EXIT_FAILURE);//EXIT_FAILURE 1
	}
	//为数组元素赋值
	printf("Enter the values(q to quit):");
	while(i < max && scanf("%lf",&ptd[i]) == 1)
	{
		++i;
	}
	//数组元素个数
	printf("Here are your %d entries.\n",number = i);
	//输出数组元素
	for(i = 0;i < number;i++)
	{
		printf("%7.2f ",ptd[i]);
		if(i % 7 == 6)
		{
			putchar('\n');
		}
	}
	if(i % 7 != 0)
	{
		putchar('\n');
	}
	puts("Done.");
	free(ptd);
	return 0;
}