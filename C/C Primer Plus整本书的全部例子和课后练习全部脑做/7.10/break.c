#include<stdio.h>

int main(void)
{
	float length,width;
	
	printf("Enter the length of the rectangle:\n");
	while(scanf("%f",&length) == 1)
	{
		printf("length = %.2f.\n",length);
		printf("Enter the width of the rectangle: \n");
		if(scanf("%f",&width) != 1)
		{
			break;
		}
		printf("width = %.2f.\n",width);
		printf("Area = %.2f.\n",length*width);
		printf("Enter the length of the rectangle:\n");
	}
	printf("Done. \n");
	return 0;
}