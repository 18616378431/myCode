#include<stdio.h>

int main(void)
{
	int a=1,b=1;
	int aplus,plusb;
	aplus=a++;	//��׺
	plusb=++b;	//ǰ׺
	printf("a	aplus	b	plusb. \n");
	printf("%d\t%d\t%d\t%d \n",a,aplus,b,plusb);
	return 0;
}