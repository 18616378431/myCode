//5.定义一个类
#ifndef BANK_H_
#define BANK_H_

class BankAccount
{
private:
	//enum{LEN = 40};
	static const int LEN = 40;
	char name[LEN];
	char accountid[LEN];
	double balance;
public:
	//默认构造函数
	BankAccount();
	//构造函数
	BankAccount(const char * p_name,const char * p_accountid = "no accountid",double p_balance = 0.0);
	//显示对象信息
	void show()const;
	//存入
	void deposit(double cash);
	//取出
	void withdraw(double cash);
};

#endif