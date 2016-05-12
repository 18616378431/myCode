//#include<stdio.h>
//#define SIZE 8
//
//int main(void)
//{
//	double inarr[SIZE],sumarr[SIZE];
//	int i;
//
//	printf("Input eight numbers for inarr: \n");
//	for(i=0;i<SIZE;i++)
//	{
//		scanf("%lf",&inarr[i]);
//	}
//	sumarr[0] = inarr[0];
//	for(i=1;i<SIZE;i++)
//	{
//		sumarr[i] = sumarr[i-1] + inarr[i];
//	}
//	for(i=0;i<SIZE;i++)
//	{
//		printf("%5.2f.",inarr[i]);
//	}
//	printf("\n");
//	for(i=0;i<SIZE;i++)
//	{
//		printf("%5.2f.|",sumarr[i]);
//	}
//	printf("\n");
//	return 0;
//}