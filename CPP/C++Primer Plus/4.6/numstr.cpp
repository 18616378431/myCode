#include<iostream>

using namespace std;

int main()
{
	int year;
	char address[80];

	cout << "What year was your house built?" << endl;
	(cin >> year).get();//cin >> year;cin.get();
	cout << "What is the street address?" << endl;
	cin.getline(address, 80);
	cout << "Year built:" << year << " Address: " << address << endl;
	return 0;
}