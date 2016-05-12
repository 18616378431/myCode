#include<stdio.h>

int main(void)
{
	const float MIN = 0.0f;
	const float MAX = 100.0f;

	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;
	
	printf("Enter the first score(q to quit!): ");
	while(scanf("%f",&score)  == 1)
	{
		if(score > MAX || score < MIN)
		{
			printf("%.1f is a invalid value.Try again!\n",score);
			continue;
		}
		printf("Accepting %.1f: \n",score);
		min = (score < min)?score:min;
		max = (score > max)?score:max;
		total += score;
		n++;
		printf("Enter next score(q to quit!): ");
	}
	if(n > 0)
	{
		printf("Average of %d scores is %.1f.\n",n,total/n);
		printf("Low = %.1f,high = %.1f.\n",min,max);
	}
	else
	{
		printf("There's no valid value!\n");
	}
	return 0;
}