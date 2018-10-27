#include<iostream>

using namespace std;

const int Max = 5;

int main()
{
	int golf[Max];
	cout << "Please enter your golf scores.\n";
	cout << "You must enter " << Max << " rounds.\n";
	int i;
	for(i = 0;i < Max;i++)
	{
		cout << "round #" << i + 1 << ":";
		while(!(cin >> golf[i]))
		{
			cin.clear();//reset input
			//while(cin.get() != ' ')//jump a word
			while(cin.get() != '\n')//jump to next line
				continue;
			cout << "Please enter a number:";
		}
	}
	//average
	double total = 0.0;
	for(i = 0;i < Max;i++)
		total += golf[i];
	//report
	cout << total / Max << " = average score " << Max << " rounds.\n";
	return 0;
}