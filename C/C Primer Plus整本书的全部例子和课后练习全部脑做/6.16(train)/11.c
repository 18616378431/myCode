//#include<stdio.h>
//
//int main(void)
//{
//	double i,sum,sum1,count;
//	int rf;
//	sum = 0;
//	sum1 = 0;
//	printf("Enter times:");
//	rf = scanf("%lf",&count);
//	while(rf == 1)
//	{
//		for(i = 1.0;i <= count;i++)
//		{
//			sum += 1.0/i;
//			if((int)i%2 == 0)
//			{
//				sum1 -= 1.0/i;
//			}
//			else
//			{
//				sum1 += 1.0/i;
//			}
//		}
//
//		printf("Sum is :%.2f.\n",sum);
//		printf("Sum1 is :%.2f.\n",sum1);
//		sum = 0;
//		sum1 = 0;
//		printf("Enter next times:");
//		rf = scanf("%lf",&count);
//	}
//	printf("\n");
//	return 0;
//}