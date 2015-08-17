#include<iostream>

using namespace std;

int main()
{
	cout << "Enter the start cutdown value:";
	int limit;
	cin >> limit;
	int i;
	for (i = limit; i; i--)
	{
		cout << "i = " << i << endl;
	}
	cout << "Done!That i = " << i << endl;
	return 0;
}