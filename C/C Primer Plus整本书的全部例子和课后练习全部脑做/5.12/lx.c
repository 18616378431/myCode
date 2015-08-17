#include<stdio.h>

int main(void)
{
	int y=2,n=3,nextnum,nextnum1;
	nextnum=(y+n++)*6;
	nextnum1=(y+(++n))*6;
	printf("nextnum=%d,nextnum1=%d \n",nextnum,nextnum1);
	return 0;
}