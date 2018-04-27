//7.给出习题5的构造函数的定义
#include<iostream>
#include<cstring>
#include"Bank.h"

//默认构造函数
BankAccount::BankAccount()
{
	strncpy(name,"no name",LEN - 1);
	name[LEN - 1] = '\0';
	strncpy(accountid,"no accountid",LEN - 1);
	accountid[LEN - 1] = '\0';
	balance = 0.0;
}

//构造函数
BankAccount::BankAccount(const char * p_name,const char * p_accountid /* =  */,double p_balance /* = 0.0 */)
{
	strncpy(name,p_name,LEN - 1);
	name[LEN - 1] = '\0';
	strncpy(accountid,p_accountid,LEN - 1);
	accountid[LEN - 1] = '\0';
	balance = p_balance;
}
//显示对象成员
void BankAccount::show()const
{
	using std::cout;
	using std::endl;

	cout << "name is :" << name
		<< ",accountid is:" << accountid
		<< ",balance is:" << balance << endl;
}
//存入
void BankAccount::deposit(double cash)
{
	balance += cash;
}
//取出
void BankAccount::withdraw(double cash)
{
	balance -= cash;
}