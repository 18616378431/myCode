#include<iostream>

using namespace std;

int main()
{
	const int SIZE = 20;
	char name[SIZE];
	char dessert[SIZE];

	cout << " Enter your name:";
	cin.get(name, SIZE).get();
	cout << "Enter your favotite food:";
	cin.get(dessert, SIZE).get();
	cout << "I have delicious " << dessert << " for you," << name << endl;
	return 0;
}