#include<stdio.h>

//�ⲿ������������
extern int rand1(void);
extern void srand1(int seed);

int main()
{
	int count;
	unsigned int seed;

	printf("Enter your choice for seed:\n");
	while(scanf("%u",&seed) == 1)
	{
		srand1(seed);//��������
		for(count = 0;count < 5;count++)
		{
			printf("%hd\n",rand1());
		}
		printf("Enter your choice for seed(q to quit):\n");
	}
	printf("Done.\n");
	return 0;
}