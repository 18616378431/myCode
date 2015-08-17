#include<iostream>

using namespace std;

void test()
{
	int chest = 42;
	int wast = 42;
	int insee = 42;

	cout << dec << "dec:chest = " << chest << endl;//dec以十进制输出
	cout << oct << "oct:wast = " << wast << endl;//oct以八进制输出
	cout << hex << "hex:insee = " << insee << endl;//hex以16进制输出
}

int main()
{
	int chest = 42;
	int wast = 0x42;
	int insee = 042;

	cout << "chest = " << chest << endl;
	cout << "wast = " << wast << endl;
	cout << "insee = " << insee << endl;

	test();
	return 0;
}