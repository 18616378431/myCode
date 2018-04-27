//名称空间的使用及扩展
#include<iostream>
#include "four.h"

const int N = 4;

int main()
{
	using namespace SALES;

	Sales s,s1;
	double arr[N] = {1,2,3,4};

	setSales(s,arr,N);
	showSales(s);

	setSales(s1);
	showSales(s1);
	return 0;
}