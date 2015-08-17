//对用户输入的整数求和
#include <stdio.h>

int main(void)
{
	long num;
	long sum = 0L;		//初始化为0
	int status;

	printf("Please insert an integer to be sumed.(q to quit!):");
	status = (scanf("%ld",&num) == 1);
	while(status == 1)
	{
		sum += num;
		printf("Please insert next integer(q to quit!):");
		status = scanf("%ld",&num);
	}
	printf("Those integer sum to %ld.\n",sum);
	return 0;
}
