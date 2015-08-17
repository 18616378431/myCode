#include<iostream>

using namespace std;

int main()
{
	cout << "The Amazing Account will sum and avgerage";
	cout << "Please enter five numbers:" << endl;
	double number;
	double sum = 0.0;
	for (int i = 1; i <= 5; i++)
	{
		cout << "Value " << i << ":";
		cin >> number;
		sum += number;
	}
	cout << "sum to " << sum << " and average " << sum / 5 << endl;
	return 0;
}