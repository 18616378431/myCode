#include<stdio.h>

struct gas{
	float distance;
	float gals;
	float mpg;
};
enum choice{no,yes,maybe};//0,1,2


struct gas getMpg(struct gas stru);
struct gas getMpg1(struct gas * ps);
char * test1(char * p,char ch);
void pFunc(char * (*pf)(char * p,char ch));

double f1(double x,double y);
double f2(double x,double y);
double f3(double x,double y);
double f4(double x,double y);
void showF(double (*pfu[4])(double x,double y));

int main()
{
	struct gas test = {300,50,0};
	struct gas * pt = &test;
	char * (*pf)(char * p,char ch);
	double (*pfu[4])(double x,double y) = {f1,f2,f3,f4};
	

	printf("%p,pfu[0] = %p.\n",pfu,&pfu[0]);
	showF(pfu);
	pf = test1;
	pFunc(pf);
	test = getMpg(test);
	printf("%.2f,%.2f.\n",test.mpg,pt->mpg);
	*pt = getMpg1(pt);
	printf("%.2f,%.2f.\n",test.mpg,pt->mpg);
	return 0;
}
struct gas getMpg(struct gas stru)
{
	stru.mpg = stru.distance / stru.gals;
	return stru;
}
struct gas getMpg1(struct gas * ps)
{
	ps->mpg = ps->distance / ps->gals;
	ps->mpg += 100;
	return *ps;
}
char * test1(char * p,char ch)
{
	putchar(ch);
	puts("test Function.");
	return NULL;
}
void pFunc(char * (*pf)(char * p,char ch))
{
	(*pf)(NULL,'F');
}

double f1(double x,double y)
{
	puts("f1");
	return x + y;
}
double f2(double x,double y)
{
	puts("f2");
	return x + y;
}
double f3(double x,double y)
{
	puts("f3");
	return x + y;
}
double f4(double x,double y)
{
	puts("f4");
	return x + y;
}

void showF(double (*pfu[4])(double x,double y))
{
	int i = 0;

	while(i < 4)
	{
		printf("%.2lf.\n",(*pfu)(1,2));
		pfu++;
		i++;
	}
	
}