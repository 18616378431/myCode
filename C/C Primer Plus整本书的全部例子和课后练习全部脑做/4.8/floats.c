//浮点数组合
#include<stdio.h>

int main(void)
{
	const double RENT=3852.99;

	printf("*%f* \n",RENT);			//浮点数默认输出
	printf("*%e* \n",RENT);			//以指数形式输出
	printf("*%4.2f* \n",RENT);		//以字段宽度4，小数点后精确到2位格式输出浮点数
	printf("*%3.1f* \n",RENT);		//以字段宽度3，小数点后精确到1位格式输出浮点数
	printf("*%10.3f* \n",RENT);		//以字段宽度10，小数点后精确到3位格式输出浮点数
	printf("*%10.3e* \n",RENT);		//以字段宽度10，小数点后精确到3位的指数格式输出
	printf("*%+4.2f* \n",RENT);		//以字段宽度4，带有正号符号，小数点后精确到2位格式输出浮点数
	printf("*%010.2f* \n",RENT);	//带有前导0，以字段宽度10，小数点后精确到2位格式输出浮点数
	return 0;
}