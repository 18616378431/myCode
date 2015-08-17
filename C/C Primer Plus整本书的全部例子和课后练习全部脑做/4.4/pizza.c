//计算pizza的面积，周长
#include<stdio.h>
#include<limits.h>
#define PI 3.1415926f

int main(void)
{
	float area,circum,radius;

	printf("Enter the radius of pizza:");
	scanf("%f",&radius);
	area=PI*radius*radius;
	circum=2*PI*radius;
	printf("The area of pizza is %1.2f and circum is %1.2f .\n",area,circum);
	printf("INT_MAX=%ld \n",INT_MAX);
	printf("INT_MIN=%d \n",INT_MIN);
	printf("CHAR_MAX=%d \n",CHAR_MAX);
	printf("CHAR_MIN=%d \n",CHAR_MIN);
	return 0;
}