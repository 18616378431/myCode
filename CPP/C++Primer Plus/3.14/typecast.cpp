#include<iostream>

using namespace std;

int main()
{
	int akus, bats, coots;

	akus = 19.99 + 11.99;
	bats = (int)19.99 + (int)11.99;//old C
	coots = int(19.99) + int(11.99);//new C++
	cout << "akus = " << akus << ",bats = " << bats << ",coots = " << coots << endl;
	char ch = 65;
	cout << "The ASCII code for " << ch << " is " << int(ch) << endl;
	cout << 3 / 4 << 3 % 4 << endl;
	return 0;
}