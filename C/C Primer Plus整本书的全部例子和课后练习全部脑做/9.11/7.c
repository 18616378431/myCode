//#include<stdio.h>
//
//double power(double n,int p);
//
//int main()
//{
//	double x,xpow;
//	int exp;
//
//	printf("Enter a number and the positive integer power:");
//	while(scanf("%lf%d",&x,&exp) == 2)
//	{
//		if(exp > 0 )
//		{
//			xpow = power(x,exp);
//			printf("%.3g to the power %d is %.5g.\n",x,exp,xpow);
//		}
//		else if(exp < 0)
//		{
//			xpow = power(x,-exp);
//			printf("%.3g to the power %d is 1 / %.5g.\n",x,exp,xpow);
//		}
//		else if(exp == 0)
//		{
//			xpow = power(x,exp);
//			printf("%.3g to the power %d is %.5g.\n",x,exp,xpow);
//		}
//		
//		printf("Enter next pair of numbers:");
//	}
//	return 0;
//}
//
//double power(double n,int p)
//{
//	double pow = 1;
//	int i;
//	if(0 == p)
//	{
//		pow = 1;
//	}
//	else if(0 == n)
//	{
//		pow = 0;
//	}
//	else
//	{
//		for(i = 1;i <= p;i++)
//		{
//			pow *= n;
//		}
//	}
//	return pow;
//}