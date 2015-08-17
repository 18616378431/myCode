#include<iostream>
#include<time.h>

using namespace std;

int main()
{
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout << "Integer division:9 / 5 = " << 9 / 5 << endl;
	cout << "Float-point division:9.0 / 5.0 = " << 9.0 / 5.0 << endl;
	cout << "Mixed division:9.0 / 5 = " << 9.0 / 5 << endl;
	cout << "double constants:1.e7 / 9.0 = " << 1e7 / 9.0 << endl;
	cout << "float constants:1.e7f / 9.0f = " << 1.e7f / 9.0f << endl;
	cout << time(NULL) << endl;
	return 0;
}