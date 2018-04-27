#include<iostream>

using namespace std;

int main()
{
	int i = 9;

	while(true)
	{
		if(i % 2 == 1 
			&& i % 3 == 0 
			&& i % 4 == 1
			&& (i + 1) % 5 == 0
			&& i % 6 == 3
			&& i % 7 == 0
			&& i % 8 == 1
			&& i % 9 == 0)
		{
			break;
		}
		i++;
	}
	cout << "num is " << i << endl;
	return 0;
}