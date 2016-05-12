//使用转换说明符
#include<stdio.h>
#define PI 3.1415926f

int main(void)
{
	int num=6;
	float aex=13.5;
	int cost=3100;
	printf("number=%d,aex=%f \n",num,aex);
	printf("The value of PI is %f \n",PI);
	printf("%c%d \n",'$',2*cost);
	printf("GDP 上涨了%d%% \n",num);//打印百分号%
	return 0;
}