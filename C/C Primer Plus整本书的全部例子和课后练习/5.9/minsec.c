#include<stdio.h>
#define SEC_PER_MIN 60		//每分钟秒数

int main(void)
{
	int sec,min,left;
	printf("Convert seconds to minutes and seconds.\n");
	printf("Enter the number of seconds(<=0 to quit!): \n");
	scanf("%d",&sec);		//读入秒数
	while(sec>0)
	{
		min=sec/SEC_PER_MIN;	//分钟数
		left=sec%SEC_PER_MIN;	//剩余秒数
		printf("%d is %d minutes and %d seconds.\n",sec,min,left);
		printf("Enter next value of second(<=0 to quit!): \n");
		scanf("%d",&sec);
	}
	printf("Done! \n");
	return 0;
}