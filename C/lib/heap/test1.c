#include <stdio.h>
#include <stdlib.h>

int decToBin(int n);

int main() 
{
	int a = 1;
	int b = 2;
	int *c = (int *)malloc(sizeof(int));
	int *d = &a;
	char *e;
	int i = 0;


	*c = 3;
	

	//栈 从高地址到低地址 向下增长 取值从高地址向低地址取值
	//堆 从低地址向高地址增长 向上增长 取值从低地址向高地址取值

	printf("%p\n%p\n%p\n%p\n",&a, &b, &c, c);

	printf("====\n");
	printf("%p,%d,%p\n", d, *d, &d);
	d--;
	printf("%p\n", d);
	printf("%d\n", *d);

	printf("heap====\n");
	*c = 256;
	printf("*c = %d\n", *c);
	printf("c = %p, c++ = %p, c-- = %p\n", c, c + 1, c - 1);
	printf("%ld\n", (char *)(c + 1) - (char *)c);
	printf("%p\n", (char *)c - 1);
	printf("%p\n", (char *)c - 2);
	printf("%p\n", (char *)c - 3);
	printf("%p\n", (char *)c - 4);

	// e = (char *)c - 4;
	// printf("e = %p\n", e);
	// printf("*e = %c\n", *e);
	// printf("(char *)e - 1 = %p,e - char(1) = %c\n", (char *)e - 1, *((char *)e - 1));

	for(i = 0; i <= 4; i++) 
	{
		printf("(char *)c + %d = %p,v = %d,i = %d,*c = %d\n", i, (char *)c + i, *((char *)c + i), i, *c);
		printf("(char *)c - %d = %p,v = %d,i = %d,*c = %d\n", i, (char *)c - i, *((char *)c - i), i, *c);
	}

	printf("dec2bin\n");
	printf("%d\n", decToBin(256));

	return 0;
}

int decToBin(int n)
{
	int r,res = 0,wq = 1,sum = 0;

    while(n != 0)
    {
        r = n % 2;
        n = n / 2;
        res = r * wq + res;
        wq *= 10;
    }
    return res;
}