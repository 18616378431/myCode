//13.12 抽象基类 实现文件
#include <iostream>
#include <cstring>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;

//Abstract base class
AcctABC::AcctABC(const char * s,long an,double bal)
{
	std::strncpy(fullname,s,MAX - 1);
	fullname[MAX - 1] = '\0';
	acctNum = an;
	balance = bal;
}
//in
void AcctABC::Deposit(double amt)
{
	if(amt < 0)
	{
		cout << "Negative deposit not allowed;"
			<< "deposit is cancelled.\n";
	}
	else
	{
		balance += amt;
	}
}
//out
void AcctABC::Withdraw(double amt)
{
	balance -= amt;
}
//base class protected method
ios_base::fmtflags AcctABC::SetFormat()const
{
	//set up ###.## format
	ios_base::fmtflags initialState = cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	return initialState;
}
//Brass Methods
void Brass::Withdraw(double amt)
{
	if(amt < 0)
	{
		cout << "Withdraw amount must be positive;"
			<< "withdraw cancelled.\n";
	}
	else if(amt <= Balance())
	{
		AcctABC::Withdraw(amt);
	}
	else
	{
		cout << "Withdraw amount of $" << amt
			<< " exceeds your balance.\n"
			<< "Withdraw cancelled.\n";
	}
}
void Brass::ViewAcct()const
{
	ios_base::fmtflags initialState = SetFormat();
	cout << "Brass Client:" << FullName() << endl;
	cout << "Account Number:" << AcctNum() << endl;
	cout << "Balance:$" << Balance() << endl;
	cout.setf(initialState);
}
//BrassPlus methods
BrassPlus::BrassPlus(const char * s,long an,double bal,double ml,double r):AcctABC(s,an,bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
BrassPlus::BrassPlus(const BrassPlus & ba,double ml,double r):AcctABC(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct()const
{
	ios_base::fmtflags initialState = SetFormat();
	cout << "Brass Client:" << FullName() << endl;
	cout << "Account Number:" << AcctNum() << endl;
	cout << "Balance:$" << Balance() << endl;
	cout << "Maximum loan:$" << maxLoan << endl;
	cout << "Owed to bank:$" << owesBank << endl;
	cout << "Loan rate:" << 100 * rate << endl;
	cout.setf(initialState);
}
void BrassPlus::Withdraw(double amt)
{
	ios_base::fmtflags initialState = SetFormat();
	
	double bal = Balance();
	if(amt <= bal)
	{
		AcctABC::Withdraw(amt);
	}
	else if(amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance:$" << advance << endl;
		cout << "Finance charge:$" << advance * rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
	{
		cout << "Credit limit exceeded.Transaction cancelled.\n";
	}
	
	cout.setf(initialState);
}