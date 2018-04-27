//14.12 MI
#include <iostream>
#include <cstring>
#include "workermi.h"

const int SIZE = 5;

int main()
{
	using namespace std;
	
	Worker * lolas[SIZE];
	int ct;

	for(ct = 0;ct < SIZE;ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w:waiter s:singer\n"
			<< "t:singingwaiter q:quit\n";
		cin >> choice;
		while(strchr("wstq",choice) == NULL)
		{
			cout << "Please enter a w,s,t or q:";
			cin >> choice;
		}
		if(choice == 'q')
			break;
		switch(choice)
		{
		case 'w':
			lolas[ct] = new Waiter;
			break;
		case 's':
			lolas[ct] = new Singer;
			break;
		case 't':
			lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();//eat the last \n
		lolas[ct]->Set();
	}
	cout << "\nHere is your Staff:\n";
	int i;
	for(i = 0;i < ct;i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for(i = 0;i < ct;i++)
		delete lolas[i];

	cout << "Bye\n";
	
	return 0;
}