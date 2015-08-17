//#include<stdio.h>
//
//double power(double n,int p);
//
//int main()
//{
//	double x,xpow;
//	int exp;
//
//	printf("Enter two numbers:");
//	while(scanf("%lf%d",&x,&exp) == 2)
//	{
//		xpow = power(x,exp);
//		if(exp >= 0)
//		{
//			printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
//		}
//		else
//		{
//			printf("%.3g to the power %d is 1 / %.5g\n",x,exp,xpow);
//		}
//		printf("Enter next pair of numbers:");
//	}
//	return 0;
//}
//
//double power(double n,int p)
//{
//	double pow = 1;
//	//int i;
//	/*for(i = 1;i <= p;i++)
//	{
//		pow *= n;
//	}*/
//	if(p > 0)
//	{
//		pow = n * power(n,p - 1);
//	}
//	else if(p < 0)
//	{
//		pow = n * power(n,p + 1);
//	}
//	else
//	{
//		pow = 1;
//	}
//	//printf("pow = %.2f\n",pow);
//	return pow;
//}