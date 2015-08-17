//整数，浮点数限制
#include<stdio.h>
#include<limits.h>//整数限制
#include<float.h>//浮点数限制

int main(void)
{
	printf("Some limits in this system: \n");
	printf("INT_MAX:%d \n",INT_MAX);
	printf("LLONG_MIN:%lld \n",LLONG_MIN);
	printf("One byte = %d bits in this system! \n",CHAR_BIT);
	printf("DBL_MAX:%e \n",DBL_MAX);
	printf("FLT_MIN:%e \n",FLT_MIN);
	printf("FLT_DIG:%d \n",FLT_DIG);
	printf("FLT_EPSILON:%e \n",FLT_EPSILON);
	return 0;
}