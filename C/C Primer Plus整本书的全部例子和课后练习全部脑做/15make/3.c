////λ����
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
////�����⣬һ����������int���������ظ����д�λ�ĸ���
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
////�����⣬������������ֵ��һ����ֵ��һ��λ��λ��,���ָ��λΪ�����򷵻�1�����򷵻�0
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
