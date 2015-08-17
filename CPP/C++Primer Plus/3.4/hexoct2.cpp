#include<iostream>

using namespace std;

int main()
{
	int chest = 42;
	int wast = 42;
	int insee = 42;

	cout << dec << "dec:chest = " << chest << endl;//dec以十进制输出
	cout << oct << "oct:wast = " << wast << endl;//oct以八进制输出
	cout << hex << "hex:insee = " << insee << endl;//hex以16进制输出
	return 0;
}