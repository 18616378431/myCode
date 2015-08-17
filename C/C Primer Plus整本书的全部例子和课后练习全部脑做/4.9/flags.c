//格式标记的使用示例
#include<stdio.h>

int main(void)
{
	printf("%x \t%X \t%#x \n",31,31,31);
	printf("*%d* \t*% d* \t*% d* \n",42,42,-42);
	printf("*%5d* \t*%5.3d* \t*%05d* \t*%05.3d* \n",6,6,6,6);
	return 0;
}