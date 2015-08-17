//c99代码块新规则
#include<stdio.h>

int main()
{
	int n = 10;
	int i,j;

	printf("Initially n = %d,addr = %p\n",n,&n);
	for(i = 1;i < 3;i++)
	{
		printf("Loop 1:n = %d,addr = %p\n",i,&i);
		printf("%p\n",&i);
	}
	printf("After Loop 1:n = %d,addr = %p\n",n,&n);
	for(j = 1;j < 3;j++)
	{
		int n = 30;
		printf("Loop 2:n = %d,addr = %p\n",j,&j);
		printf("Loop 2:n = %d,addr = %p\n",n,&n);
		n++;
	}
	printf("After Loop 2:n = %d,addr = %p\n",n,&n);
	return 0;
}