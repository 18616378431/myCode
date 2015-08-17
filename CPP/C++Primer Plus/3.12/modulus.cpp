//ÇóÄ£²Ù×÷·û
#include<iostream>

using namespace std;

int main()
{
	const int Labs_per_stn = 14;
	int lbs;

	cout << "Enter your weight in pounds:";
	cin >> lbs;
	int stone = lbs / Labs_per_stn;
	int pounds = lbs % Labs_per_stn;
	cout << lbs << " pounds are " << stone << " stones and " << pounds << " pound(s).\n";
	return 0;
}