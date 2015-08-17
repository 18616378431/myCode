#include<iostream>

using namespace std;

int main()
{
	const int SIZE = 20;
	char name[SIZE];
	char dessert[SIZE];

	cout << "Enter your name:";
	cin.getline(name, SIZE);
	cout << "Enter your favorite dessert:";
	cin.getline(dessert, SIZE);
	cout << "I have delicious " << dessert << " for you," << name << endl;

	return 0;
}