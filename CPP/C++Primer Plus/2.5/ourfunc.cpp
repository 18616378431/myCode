#include<iostream>

using namespace std;

void simo(int);

int main()
{
	simo(3);
	cout << "Pick an integer :";
	int count;
	cin >> count;
	simo(count);
	cout << "Done!" << endl;
	return 0;
}
void simo(int n)
{
	cout << "Simo said touch your toes " << n << " times." << endl;
}