#include<iostream>

using namespace std;

int main()
{
	int updates = 6;
	int * pu = &updates;

	cout << "updates = " << updates << " *pu = " << *pu << endl;
	cout << "updates address = " << &updates << " pu address = " << pu << endl;
	*pu += 1;
	cout << "Now updates = " << updates << endl;
	return 0;
}