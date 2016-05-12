//#组合字符串，##组合语言符号
#include<stdio.h>
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x"#n" = %d.\n",x ## n)

int main()
{
	int XNAME(1) = 12;//等价于int x1 =12;
	int XNAME(2) = 24;
	PRINT_XN(1);
	PRINT_XN(2);
	return 0;
}