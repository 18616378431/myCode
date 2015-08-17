#include<iostream>
using namespace std;

int main()
{
	int h = 3;
	int * pt = &h;

	cout << "h: Value:" << h << " Address:" << &h << endl;
	cout << "*pt: Value:" << *pt << " Address:" << pt << endl;
	return 0;
}