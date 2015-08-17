#include<iostream>

using namespace std;

int main()
{
	const int SIZE = 20;
	char name[SIZE];
	char dessert[SIZE];

	cout << "Enter your name:";
	cin >> name;
	cout << "Enter your favorite food:";
	cin >> dessert;
	cout << "I have some delicious " << dessert << " for you," << name << endl;
	return 0;
}