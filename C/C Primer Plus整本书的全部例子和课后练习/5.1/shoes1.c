//把一双鞋的尺码转换为英寸
#include<stdio.h>
#define ADJUST 7.64
#define SCALE 0.325

int main(void)
{
	float shoe,foot;
	shoe=9.0;
	foot=SCALE*shoe+ADJUST;
	printf("Shoes size(men's) foot length:%10.1f and %15.2f inch! \n",shoe,foot);
	return 0;
}