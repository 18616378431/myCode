#include<stdio.h>
//3
#define MIN(X,Y) (X) < (Y)?(X):(Y)
//4
#define EVEN_GT(X,Y) (X) % 2 == 0?((X) > (Y)?1:0):0
//5
#define SHOW_V(X,Y) printf(#X" is %d and "#Y" is %d.\n",X,Y)
//6
#define NUM 25
#define SPACE ' '
#define PS() putchar(SPACE)
#define BIG(X) ((X) + 3)
#define SUMSQ(X,Y) (X) * (X) + (Y) * (Y)
//7
#define SHOW_VAR(X) printf("name:"#X";value:%d;address:%p.\n",X,&X)
//8
#define _SKIP_
//9
#define PR_DATE

int main()
{
	int x = 6,y = 3;

	printf("The min is %d.\n",MIN(x,y));
	printf("The result is %d.\n",EVEN_GT(x,y));
#ifndef _SKIP_
	SHOW_V(3+4,4*12);
#endif
	SHOW_VAR(x);
#ifdef PR_DATE
	printf("Date is %s.\n",__DATE__);
#endif
	return 0;
}