#include <stdio.h>

int main(void)
{
	const int NUMBER = 22;
	int count;
	for(count = 1;count < NUMBER;count++)
	{
		printf("count is %d.\n",count);
	}
	return 0;
}