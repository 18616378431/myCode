//常规new操作符和布局new操作符
#include<iostream>
#include<new>//布局new操作符头文件

using namespace std;

const int BUF = 512;
const int N = 5;
char buffer[BUF];//块内存

int main()
{
	double *pd1,*pd2;
	int i;
	cout << "Calling new and placement new:\n";
	pd1 = new double[N];//常规new
	pd2 = new (buffer) double[N];//布局操作符new,从buffer中为double数组分配内存
	for(i = 0;i < N;i++)
	{
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}
	cout << "Buffer addresses:\n" << " heap:" << pd1
		<< " static:" << (void *)buffer << endl;
	cout << "Buffer contents:\n";
	for(i = 0;i < N;i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}

	cout << "\nCalling new and placement new a second time:\n";
	double *pd3,*pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];
	for(i = 0;i < N;i++)
	{
		pd3[i] = pd4[i] = 1000 + 20.0 * i;
	}
	cout << "Buffer contents:\n";
	for(i = 0; i < N;i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << ";";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}

	cout << "Calling new and placement new a third time:\n";
	delete [] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for(i = 0;i < N;i++)
	{
		pd1[i] = pd2[i] = 1000 + 20.0 * i;
	}
	cout << "Buffer contents:\n";
	for(i = 0;i < N;i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	delete [] pd1;
	delete [] pd3;
	return 0;
}