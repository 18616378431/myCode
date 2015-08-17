////位操作
//#include<stdio.h>
//#define BOOL int
//#define true 1
//#define false 0
//
//int open(int n);
//int isOpen(int num,int bit_position);
//void itobs(unsigned int n);
//
//int main()
//{
//	int num;
//
//	printf("Enter a number:\n");
//	scanf("%d",&num);
//	printf("There is %d bits is opening.\n",open(num));
//	printf("%d's 2 is %d.\n",num,isOpen(num,3));
//	itobs(num);
//	putchar('\n');
//	
//	return 0;
//}
////第三题，一个函数接收int参数，返回该数中打开位的个数
//int open(int n)
//{
//	int ct = 0;
//	static int size = 8 * sizeof(int);
//
//	while(size-- > 0)
//	{
//		if(01 & n)
//			ct++;
//		n >>= 1;
//	}
//	return ct;
//}
////第四题，函数接收两个值，一个数值，一个位的位置,如果指定位为开，则返回1，否则返回0
//int isOpen(int num,int bit_position)
//{
//	BOOL isOpen = false;
//
//	
//	if(01 & (num >> bit_position))
//		isOpen = true;
//	return isOpen;
//}
//void itobs(unsigned int n)
//{
//	int r;
//
//	r = n % 2;
//	if(n >= 2)
//		itobs(n / 2);
//	putchar('0' + r);
//}
