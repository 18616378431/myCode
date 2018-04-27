//使用名称空间的开放性添加名称空间中的函数定义
#include <iostream>
#include "namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;
	void getPerson(Person & rp)
	{
		cout << "Enter the first name:";
		cin >> rp.fname;
		cout << "Enter the last name:";
		cin >> rp.lname;
	}
	void showPerson(const Person & rp)
	{
		std::cout << rp.lname << "," << rp.fname;
	}
}
namespace debts
{
	void getDebt(Debt & rd)
	{
		getPerson(rd.name);
		std::cout << "Enter debt:";
		std::cin >> rd.amount;
	}
	void showDebt(const Debt & rd)
	{
		showPerson(rd.name);
		std::cout << ":$" << rd.amount << std::endl;
	}
	double sumDebts(const Debt ar[],int n)
	{
		double total = 0;
		for(int i = 0;i < n;i++)
		{
			total += ar[i].amount;
		}
		return total;
	}
}