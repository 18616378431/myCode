#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

void showArray(const double arr[],int n);
double * new_d_array(int n,...);

int main()
{
	double * p1;
	double * p2;
	
	p1 = new_d_array(5,1.2,2.3,3.4,4.5,5.6);
	p2 = new_d_array(4,100.00,20.00,8.08,-1890.0);
	showArray(p1,5);
	showArray(p2,4);
	free(p1);
	free(p2);
	return 0;
}
double * new_d_array(int n,...)
{
	double * new_p = malloc(n * sizeof(double));
	va_list ap;//用于存储可变参数
	int i;
	double get;

	va_start(ap,n);
	for(i = 0;i < n;i++)
	{
		get = va_arg(ap,double);
		printf("%.2lf.\n",get);
		new_p[i] = get;
	}
	va_end(ap);
	return new_p;
}
void showArray(const double arr[],int n)
{
	int i;

	for(i = 0;i < n;i++)
		printf("%10.2lf",arr[i]);
	putchar('\n');
}