#include<iostream>
#include<climits>

using namespace std;

int main()
{
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;

	//bytes
	cout << "int is " << sizeof(int) << " bytes." << endl;
	cout << "short is " << sizeof(n_short) << " bytes." << endl;
	cout << "long is " << sizeof(n_long) << " bytes." << endl << endl;;
	//Max value
	cout << "Maximum values:" << endl;
	cout << "int :" << n_int << endl;
	cout << "short :" << n_short << endl;
	cout << "long :" << n_long << endl << endl;

	//MIN
	cout << "Minimum int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;
	return 0;
}