//13.10 使用指向对象的指针或引用以使用虚方法特性virtual
#include <iostream>
#include "brass.h"

const int CLIENTS = 4;
const int LEN = 40;

int main()
{
	using namespace std;

	//指向Brass对象的指针数组,基类指针或引用可以指向派生类(Brass,BrassPlus)
	Brass * p_clients[CLIENTS];

	int i;
	for(i = 0;i < CLIENTS;i++)
	{
		char temp[LEN];
		long tempnum;
		double tempbal;
		char kind;
		cout << "Enter client's name:";
		cin.getline(temp,LEN);
		cout << "Enter client's Account number:";
		cin >> tempnum;
		cout << "Enter opening balance:";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or 2 for BrassPlus Account:";
		while(cin >> kind && (kind != '1' && kind != '2'))
		{
			cout << "Enter either 1 or 2:";
		}
		if(kind == '1')
		{
			p_clients[i] = new Brass(temp,tempnum,tempbal);
		}
		else
		{
			double tmax,trate;
			cout << "Enter the overdraft limit:$";
			cin >> tmax;
			cout << "Enter the interest rate as a decimal fraction:";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp,tempnum,tempbal,tmax,trate);
		}
		while(cin.get() != '\n')
		{
			continue;
		}
	}
	cout << endl;
	for(i = 0;i < CLIENTS;i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for(i = 0;i < CLIENTS;i++)
	{
		delete p_clients[i];//free memory
	}
	cout << "Done.\n";

}
