#include<iostream>
using namespace std;

int main()
{
	int * p = new int;//Ϊintָ�����int���ʹ�С�ڴ�
	*p = 100;//����Ϊ�丳ֵ
	cout << "int Value:" << *p << " Address:" << p << endl;
	double * pd = new double;
	*pd = 10000001.0;
	cout << "double Value:" << *pd << " Address:" << pd << endl;
	cout << "sizeof(p):" << sizeof(p) << " sizeof(*p)" << sizeof(*p) << endl;
	cout << "sizeof(pd):" << sizeof(pd) << " sizeof(*pd)" << sizeof(*pd) << endl;
	return 0;
}