////2.
////(a)void dcount(int num);
////(b)int gear(int a,int b);
////(c)void stuff_it(double a,double * p);
////3.
////(a)char n_to_char(int a);
////(b)int digits(double a,int b);
////(c)int random(void);
//4.5.
//#include<stdio.h>
//
//double plus(double x,double y);
//
//int main()
//{
//	double a,b;
//
//	printf("Enter two interger values :");
//	scanf("%lf%lf",&a,&b);
//	printf("%.2f + %.2f = %.2f.\n",a,b,plus(a,b));
//	return 0;
//}
//
//double plus(double x,double y)
//{
//	return (x + y);
//}
//6.
//#include <stdio.h>
//
//void alter(int * x,int * y);
//
//int main()
//{
//	int a,b;
//
//	printf("Enter two interger values :");
//	scanf("%d%d",&a,&b);
//	printf("Originally a = %d and b = %d.\n",a,b);
//	alter(&a,&b);
//	printf("Now a = %d and b= %d.\n",a,b);
//	return 0;
//}
//
//void alter(int * x,int * y)
//{
//	int mul,sub;
//	
//	mul = *x + *y;
//	sub = *x - *y;
//	*x = mul;
//	*y = sub;
//}
//7.
//#include<stdio.h>
//
//int getMax(int x,int y,int z);
//
//int main()
//{
//	int a,b,c;
//	int max;
//	printf("Enter three integer values:");
//	scanf("%d%d%d",&a,&b,&c);
//	max = getMax(a,b,c);
//	printf("The maxium in %d,%d and %d is %d.\n",a,b,c,max);
//	return 0;
//}
//int getMax(int x,int y,int z)
//{
//	int max;
//	if(x >= y && x >= z)
//	{
//		max = x;
//	}
//	if(z >= x && z >= y)
//	{
//		max= z;
//	}
//	if(y >= x && y >= z)
//	{
//		max = y;
//	}
//	return max;
//}
//#include<stdio.h>
//#define START "*******************************"
//void menuShow(void);
//int lowAndhigh(int low,int high);
//
//int main()
//{
//	int a;
//	menuShow();
//	a = lowAndhigh(1,4);
//	switch(a)
//	{
//	case 1:
//		printf("copy files.\n");
//		break;
//	case 2:
//		printf("move files.\n");
//		break;
//	case 3:
//		printf("remove files.\n");
//		break;
//	case 4:
//		printf("quit.\n");
//		break;
//	}
//	return 0;
//}
//
//void menuShow(void)
//{
//	printf("%s\n",START);
//	printf("Please choose one of the following:\n");
//	printf("1)copy files 2)move files\n");
//	printf("3)remove files 4)quit\n");
//	printf("Enter the number of your choice:\n");
//	printf("%s\n",START);
//}
//
//int lowAndhigh(int low,int high)
//{
//	int input;
//	int status;
//	while((status = scanf("%d",&input)) != 1 || (input > high || input < low))
//	{
//		if(getchar() == 'q')
//		{
//			break;
//		}
//		menuShow();
//		while(getchar() != '\n')
//		{
//			continue;
//		}
//	}
//	return input;
//}