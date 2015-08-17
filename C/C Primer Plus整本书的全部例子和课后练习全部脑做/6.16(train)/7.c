//#include<stdio.h>
//
//double math(double x,double y);
//
//int main(void)
//{
//	double v1,v2,s;
//	int rf;
//	printf("Enter v1 and v2(q to quit):");
//	rf = scanf("%lf%lf",&v1,&v2);
//	while(rf == 2)
//	{
//		s = math(v1,v2);
//		printf("The value is %.2f.\n",s);
//		printf("Enter v1 and v2:");
//		rf = scanf("%lf%lf",&v1,&v2);
//	}
//	return 0;
//}
//
//double math(double x,double y)
//{
//	double sum;
//	sum = (y - x)/(y*x);
//	return sum;
//}