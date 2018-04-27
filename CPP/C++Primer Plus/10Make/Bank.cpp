//7.����ϰ��5�Ĺ��캯���Ķ���
#include<iostream>
#include<cstring>
#include"Bank.h"

//Ĭ�Ϲ��캯��
BankAccount::BankAccount()
{
	strncpy(name,"no name",LEN - 1);
	name[LEN - 1] = '\0';
	strncpy(accountid,"no accountid",LEN - 1);
	accountid[LEN - 1] = '\0';
	balance = 0.0;
}

//���캯��
BankAccount::BankAccount(const char * p_name,const char * p_accountid /* =  */,double p_balance /* = 0.0 */)
{
	strncpy(name,p_name,LEN - 1);
	name[LEN - 1] = '\0';
	strncpy(accountid,p_accountid,LEN - 1);
	accountid[LEN - 1] = '\0';
	balance = p_balance;
}
//��ʾ�����Ա
void BankAccount::show()const
{
	using std::cout;
	using std::endl;

	cout << "name is :" << name
		<< ",accountid is:" << accountid
		<< ",balance is:" << balance << endl;
}
//����
void BankAccount::deposit(double cash)
{
	balance += cash;
}
//ȡ��
void BankAccount::withdraw(double cash)
{
	balance -= cash;
}