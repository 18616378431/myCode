#include<stdio.h>

int main(void)
{
	const int FREEZING = 0;
	float temperature;
	int cold_day = 0;
	int all_day = 0;

	printf("Enter the low temperature(q to quit!):\n");
	while(scanf("%f",&temperature) == 1)
	{
		all_day++;
		if(temperature < 0)
		{
			cold_day++;
		}
	}
	if(all_day != 0)
	{
		printf("%d total days!%.1f%% were below freezing!\n",all_day,((float)cold_day/all_day)*100.0);
	}
	else
	{
		printf("No data entered! \n");
	}

	return 0;
}