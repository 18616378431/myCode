//5.����һ����
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
	//Ĭ�Ϲ��캯��
	BankAccount();
	//���캯��
	BankAccount(const char * p_name,const char * p_accountid = "no accountid",double p_balance = 0.0);
	//��ʾ������Ϣ
	void show()const;
	//����
	void deposit(double cash);
	//ȡ��
	void withdraw(double cash);
};

#endif