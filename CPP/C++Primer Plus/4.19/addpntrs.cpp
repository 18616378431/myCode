#include<iostream>
using namespace std;

int main()
{
	double wage[3] = {10000.0,20000.0,30000.0};
	short stack[3] = {3,2,1};
	double * pd = wage;
	short * ps = &stack[0];

	cout << "pd:" << pd << " *pd:" << *pd << endl;
	cout << "add one to pd:" << endl;
	pd += 1;
	cout << "pd:" << pd << " *pd:" << *pd << endl;

	cout << "ps:" << ps << " *ps:" << *ps << endl;
	cout << "add one to pd:" << endl;
	ps += 1;
	cout << "ps:" << ps << " *ps:" << *ps << endl;

	cout << "Array:		stack[0]:" << stack[0] << " stack[1]:" << stack[1] << endl;
	cout << "Pointer:		*stack:" << *stack << " *(stack + 1):" << *(stack + 1) << endl;

	cout << "sizeof(wage):" << sizeof(wage) << endl;
	cout << "sizeof(pd):" << sizeof(pd) << endl;
	return 0;
}