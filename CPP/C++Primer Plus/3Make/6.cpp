#include<iostream>

#define M_PER_K 62.14
#define S_TO_G 3.875

using namespace std;

int main()
{
	float s;
	float k;

	cout << "Enter s:";
	cin >> s;
	cout << "American: " << M_PER_K / (s / S_TO_G) << " miles per galen" << endl;
	cout << 62.14 / (12.4 / 3.875) << endl;
	return 0;
}