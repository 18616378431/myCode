//14.9 MI
#include <iostream>
#include "worker0.h"

const int LIM = 4;

int main()
{
	using namespace std;

	//test case
	//pure abstract class instance error
	//Worker ttt;
	
	//private is default for class member
	//Test a;

	//cout << a.a;
	//cout << a.b;
	//cout << a.c;

	Waiter bob("Bob Apple",314L,5);
	Singer bev("Beverly Hills",522L,3);
	Waiter w_temp;
	Singer s_temp;

	Worker *pw[LIM] = {&bob,&bev,&w_temp,&s_temp};

	int i;
	for(i = 2;i < LIM;i++)
	{
		pw[i]->Set();
	}
	for(i = 0;i < LIM;i++)
	{
		pw[i]->Show();
		cout << endl;
	}

	return 0;
}