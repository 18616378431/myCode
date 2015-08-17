#include<iostream>
#include<string>

using namespace std;

const int arrSize = 20;

int main()
{
	string name;
	cout << "Your first name Please:";
	cin >> name;
	cout << "Here is your name:\n";
	int i = 0;
	while (name[i] != '\0')
	{
		cout << name[i] << " : " << int(name[i]) << endl;
		i++;
	}
	return 0;
}