//����ǰ20��������ƽ����
#include<stdio.h>

int main(void)
{
	int num=1;
	int squares;
	while(num<=20)
	{
		squares=num*num;
		printf("%4d squares is :%6d \n",num,squares);
		num=num+1;
	}
	return 0;
}