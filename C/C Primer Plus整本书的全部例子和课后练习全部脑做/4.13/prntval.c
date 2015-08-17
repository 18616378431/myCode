//printf函数的返回值
#include<stdio.h>

int main(void)
{
	int bph2o=212;
	int rv;
	
	rv=printf("%d is water's boilling point! \n",bph2o);
	printf("%d \n",rv);
	return 0;
}