//使用可变宽度的输出字段
#include<stdio.h>

int main(void)
{
	unsigned width,precision;	//声明字段宽度，精度变量
	int number=256;
	double weight=242.5;

	printf("What filed width? \n");
	scanf("%d",&width);
	printf("The number is : %*d \n",width,number);
	printf("Enter width and precision:");
	scanf("%d %d",&width,&precision);
	printf("Weight:%*.*f \n",width,precision,weight);
	return 0;
}