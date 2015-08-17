#include<iostream>
using namespace std;

int main()
{
	int * p = new int;//为int指针分配int类型大小内存
	*p = 100;//可以为其赋值
	cout << "int Value:" << *p << " Address:" << p << endl;
	double * pd = new double;
	*pd = 10000001.0;
	cout << "double Value:" << *pd << " Address:" << pd << endl;
	cout << "sizeof(p):" << sizeof(p) << " sizeof(*p)" << sizeof(*p) << endl;
	cout << "sizeof(pd):" << sizeof(pd) << " sizeof(*pd)" << sizeof(*pd) << endl;
	return 0;
}