#include<stdio.h>
#include<math.h>//pow(2,3)求2的三次方
#define LEN 100

void transform(double * source,double * target,int size,double (*sin)(double));
double mutiplyTwo(double n);
double divideTwo(double n);
void delMore();
void init(double * source);

int main()
{
	double source[LEN];
	double target[LEN];
	int i;
	char ch;
	double (*pfun[4])(double) = {mutiplyTwo,divideTwo,sqrt,log};

	//pow(2,3);
	//sqrt(100);
	//log(1);
	init(source);
	puts("Enter your choice,Please input a b c or d:");
	i = 0;
	while(i < 4 && (ch = getchar()) != 'q')
	{
		switch(ch)
		{
		case 'a':
			puts("MutiplyTwo");
			transform(source,target,LEN,pfun[0]);
			break;
		case 'b':
			puts("DivideTwo");
			transform(source,target,LEN,pfun[1]);
			break;
		case 'c':
			puts("sqrt");
			transform(source,target,LEN,pfun[2]);
			break;
		case 'd':
			puts("log");
			transform(source,target,LEN,pfun[3]);
			break;
		default:
			puts("Please input a b c or d:");
			break;
		}
		i++;
		puts("Enter your choice:");
		delMore();
		init(source);
	}
	return 0;
}
void transform(double * source,double * target,int size,double (*sin)(double))
{
	int i;

	for(i = 0;i < size;i++)
	{
		target[i] = (*sin)(source[i]);
	}
	for(i = 0;i < size;i++)
	{
		printf("target[%d] = %.2lf.\n",i,target[i]);
	}
}

double mutiplyTwo(double n)
{
	n *= 2;
	return n;
}
double divideTwo(double n)
{
	n /= 2;
	return n;
}
void delMore()
{
	while(getchar() != '\n')
		continue;
}
void init(double * source)
{
	int i;
	//初始化源数组
	for(i = 0;i < LEN;i++)
	{
		source[i] = i + 1;
	}
}