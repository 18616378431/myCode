//14.11 MI
#include <iostream>
#include "workermi.h"

using std::cout;
using std::cin;
using std::endl;

//Worker methods
Worker::~Worker(){}

//protected
void Worker::Data()const
{
	cout << "Name:" << fullname << endl;
	cout << "ID:" << id << endl;
}
void Worker::Get()
{
	getline(cin,fullname);
	cout << "Enter id:";
	cin >> id;
	while(cin.get() != '\n')
		continue;
}
//Waiter methods
void Waiter::Set()
{
	cout << "Enter waiter's name:";
	Worker::Get();
	Get();
}
void Waiter::Show()const
{
	cout << "Category:waiter\n";
	Worker::Data();
	Data();
}
//protected
void Waiter::Data()const
{
	cout << "Panache:" << panache << endl;
}
void Waiter::Get()
{
	cout << "Enter Waiter's panache:";
	cin >> panache;
	while(cin.get() != '\n')
		continue;
}
//Singer methods
char * Singer::pv[Singer::Vtypes] = {"other","alto","contralto","soprano","bass","baritone","tenor"};

void Singer::Set()
{
	cout << "Enter Singer's name:";
	Worker::Get();
	Get();
}
void Singer::Show()const
{
	cout << "Category:Singer\n";
	Worker::Data();
	Data();
}
//protected
void Singer::Data()const
{
	cout << "Voice:" << pv[voice] << endl;
}
void Singer::Get()
{
	cout << "Enter Singer's voice:";
	int i;
	for(i = 0;i < Vtypes;i++)
	{
		cout << i << ":" << pv[i] << " ";
		if(i % 4 == 3)
			cout << endl;
	}
	if(i % 4 != 0)
		cout << endl;
	cin >> voice;
	while(cin.get() != '\n')
		continue;
}
//SingingWaiter methods
//protected
void SingingWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();
}
void SingingWaiter::Get()
{
	Singer::Get();
	Waiter::Get();
}
void SingingWaiter::Set()
{
	cout << "Enter SingingWaiter's name:";
	Worker::Get();
	Get();
}
void SingingWaiter::Show()const
{
	cout << "Category:SingingWaiter\n";
	Worker::Data();
	Data();
}