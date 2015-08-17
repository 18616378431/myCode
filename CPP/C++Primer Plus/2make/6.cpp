#include<iostream>

using namespace std;

void ShowTime(int h, int m);

int main()
{
	int hour, min;

	cout << "Enter the number of hours:";
	cin >> hour;
	cout << "Enter the number of minute:";
	cin >> min;
	ShowTime(hour,min);
	return 0;
}
void ShowTime(int h, int m)
{
	cout << "Time:" << h << " : " << m << endl;
}