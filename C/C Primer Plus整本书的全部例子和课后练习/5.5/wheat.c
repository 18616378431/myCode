//指数增长
#include<stdio.h>
#define SQUARES 64 //棋盘上方格数量
#define CROP 1E15  //粒记 美国小麦产量

int main(void)
{
	int count=1;
	double total,current;
	printf("square grains total		");
	printf("fraction of \n");
	printf("add		grain		");
	printf("US total \n");
	total=current=1.0;		//以一粒开始
	printf("%4d %13.2e %12.2e %12.2e \n",count,current,total,total/CROP);
	while(count<SQUARES)
	{
		count=count+1;
		current=2*current;
		total=total+current;
		printf("%4d %13.2e %12.2e %12.2e \n",count,current,total,total/CROP);
	}
	return 0;
}