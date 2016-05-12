//输出类型的大小
#include<stdio.h>

int main(void)
{
	printf("Type char has a size of %u bytes! \n",sizeof(char));
	printf("Type short has a size of %u bytes! \n",sizeof(short));
	printf("Type int has a size of %u bytes! \n",sizeof(int));
	printf("Type long has a size of %u bytes! \n",sizeof(long));
	printf("Type float has a size of %u bytes! \n",sizeof(float));
	printf("Type double has a size of %u bytes! \n",sizeof(double));
	printf("Type long long has a size of %u bytes! \n",sizeof(long long));
	return 0;
}