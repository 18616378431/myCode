//#include<stdio.h>
//
////º¯ÊýÉùÃ÷
//long fact(int n);
//long rfact(int n);
//
//int main()
//{
//	int num;
//	printf("This program calculates factorials.\n");
//	printf("Enter a value in the range 0 - 12(q to quit!):");
//	while(scanf("%d",&num) == 1)
//	{
//		if(num < 0)
//		{
//			printf("No negative numbers,please.\n");
//		}
//		else if(num > 12)
//		{
//			printf("Keep input under 13.\n");
//		}
//		else
//		{
//			printf("loop:%d factorial = %ld\n",num,fact(num));
//			printf("recursion:%d factorial = %ld\n",num,rfact(num));
//		}
//		printf("Enter a value in the range 0 - 12(q to quit!):");
//	}
//	printf("Bye.\n");
//	return 0;
//}
//
//long fact(int n)
//{
//	int i;
//	long ans = 1;
//	for(i = 1;i <= n;i++)
//	{
//		ans *= i;
//	}
//	return ans;
//}
//
//long rfact(int n)
//{
//	long ans;
//	if(0 == n)
//	{
//		ans = 1;
//	}
//	else
//	{
//		ans  = n * rfact(n - 1);
//		/*n:5;
//		ans = 5 * rfact(5 - 1) = 5 * rfact(4);
//		ans = 5 * 4 * rfact(3);
//		ans = 5 * 4 * 3 * rfact(2);
//		ans = 5 * 4 * 3 * 2 * rfact(1);
//		ans = 5 * 4 *3 *2 * 1;*/
//	}
//	return ans;
//}