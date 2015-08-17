#include<iostream>

using namespace std;

const int ArrSize = 16;

int main()
{
	double factorials[ArrSize];
	factorials[0] = factorials[1] = 1.0;
	int i;
	for (i = 2; i < ArrSize; i++)
	{
		factorials[i] = i * factorials[i - 1];
	}
	for (i = 0; i < ArrSize; i++)
	{
		cout << i << "! = " << factorials[i] << endl;
	}
	return 0;
}