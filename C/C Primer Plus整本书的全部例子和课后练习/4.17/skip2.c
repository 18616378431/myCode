//���������ǰ��������
#include<stdio.h>

int main(void)
{
	int n;
	printf("Enter three integers:");
	scanf("%*d %*d %d",&n,&n,&n);
	printf("%d \n",n);
	return 0;
}