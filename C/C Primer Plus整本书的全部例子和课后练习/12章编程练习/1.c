////不使用全局变量重写12.4
//#include<stdio.h>
//
//int critic(int n);
//
//int main()
//{
//	int units = 0;
//
//	printf("How many pounds of a frikin butter?\n");
//	while(scanf("%d",&units) == 1)
//	{
//		if(critic(units) == 56)
//		{
//			break;
//		}
//	}
//	return 0;
//}
//
//int critic(int n)
//{
//	if(n != 56)
//		printf("No,luck chimum!Try again!\n");
//	else
//		printf("You must have looked it up!\n");
//	return n;
//}
