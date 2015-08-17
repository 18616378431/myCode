//#include<stdio.h>
//
//int main(void)
//{
//	int a;		//要检查的数
//	int div;		//可能的约数
//	int count = 0;
//
//	printf("Enter an integer number:\n");
//	scanf("%d",&a);
//	while(a > 0)
//	{
//		
//		for(div = 2;(div * div) <= a;div++)
//		{
//			if(a % div == 0)
//			{
//				count++;
//			}
//		}
//		if(count == 0)
//		{
//			printf("%d is a prime.\n",a);
//		}
//		else
//		{
//			//printf("%d is not a prime.\n",a);
//			count = 0;
//		}
//		a--;
//	}
//	return 0;
//}