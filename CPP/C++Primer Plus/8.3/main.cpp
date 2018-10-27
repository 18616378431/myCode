#include<iostream>

using namespace std;

int main(int argc,char* argv[])
{
	int rats = 101;
	int & rodents = rats;

	cout << "rats = " << rats << endl;
	cout << "rodents = " << rodents << endl;

	cout << "address rats = " << &rats << endl;
	cout << "address rodents = " << &rodents << endl;

	int bunnies = 50;
	rodents = bunnies;

	cout << "bunnies = " << bunnies << endl;
	cout << "rats = " << rats << endl;
	cout << "rodents = " << rodents << endl;

	cout << "address bunnies = " << &bunnies << endl;
	cout << "address rodents = " << &rodents << endl;

	return 0;
}