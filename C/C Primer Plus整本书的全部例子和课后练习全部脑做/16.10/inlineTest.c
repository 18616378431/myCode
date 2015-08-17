#include<stdio.h>
//内联函数
inline void eatLine()//C99特性
{
	while(getchar() != '\n')
		continue;
}
extern double square(double);//同一文件中可以将square()声明为外部函数
inline double square(double);
double square(double x)
{
	return x * x;
}

int main()
{
	eatLine();
	return 0;
}