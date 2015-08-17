#include<iostream>

using namespace std;

int main()
{
	float hats, head;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Enter a number:";
	cin >> hats;
	cout << "Enter another number:";
	cin >> head;
	cout << "hats = " << hats << ",head = " << head << endl;
	cout << "hats + head = " << hats + head << endl;
	cout << "hats - head = " << hats - head << endl;
	cout << "hats * head = " << hats * head << endl;
	cout << "hats / head = " << hats / head << endl;
	return 0;
}