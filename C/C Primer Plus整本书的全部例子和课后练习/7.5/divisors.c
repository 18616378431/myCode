//ʹ��һ��Ƕ��if��ʾһ������Լ��
#include<stdio.h>
//#include<stdbool.h>
#define TRUE 1
#define FALSE 0

int main(void)
{
	unsigned long num;		//Ҫ������
	unsigned long div;		//���ܵ�Լ��
	int isPrime;		//������־

	printf("Please enter an integer for analysis: ");
	printf("Enter q to quit!\n");
	while(scanf("%lu",&num) == 1)
	{
		for(div = 2,isPrime = TRUE;(div * div) <= num; div++)
		{
			if(num % div == 0)
			{
				if((div*div) != num)
				{
					printf("%lu is divisible by %lu and % lu.\n",num,div,num/div);	
				}
				else
				{
					printf("%lu is divisible by %lu.\n",num,div);
				}
				isPrime = FALSE;	//����һ������
			}
		}
		if(isPrime)
		{
			printf("%lu is prime.\n",num);
		}
		printf("Please enter another integer for analysis: ");
		printf("Enter q to quit!\n");
	}
	printf("Bye.\n");
	return 0;
}