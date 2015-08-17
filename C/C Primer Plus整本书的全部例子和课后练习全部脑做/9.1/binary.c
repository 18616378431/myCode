//#include<stdio.h>
//
//void to_binary(unsigned long n);
//
//int main()
//{
//	unsigned long num;
//	printf("Enter an integer number(q to quit!):");
//	
//	while(scanf("%ul",&num) == 1)
//	{
//		printf("Binary equivalent: ");
//		to_binary(num);
//		putchar('\n');
//		printf("Enter an interger(q to quit!):");
//	}
//	printf("Done.\n");
//	return 0;
//}
//void to_binary(unsigned long n)
//{
//	int r;
//	r = n % 2;
//	if(n >= 2)
//		to_binary(n / 2);
//	/*1
//	n:9;
//	r = 9 % 2 = 1;
//	2
//	n:9 / 2 = 4;
//	r =  4 % 2 = 0;
//	3
//	n:4 / 2 = 2;
//	r = 2 % 2 = 0;
//	4
//	n:2 / 2 = 1;
//	r= 1 % 2 = 1;
//	4:1;
//	3:0;
//	2:0;
//	1:1;*/
//	putchar('0' + r);
//
//	return;
//}