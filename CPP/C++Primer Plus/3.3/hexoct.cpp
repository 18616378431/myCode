#include<iostream>

using namespace std;

void test()
{
	int chest = 42;
	int wast = 42;
	int insee = 42;

	cout << dec << "dec:chest = " << chest << endl;//dec��ʮ�������
	cout << oct << "oct:wast = " << wast << endl;//oct�԰˽������
	cout << hex << "hex:insee = " << insee << endl;//hex��16�������
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