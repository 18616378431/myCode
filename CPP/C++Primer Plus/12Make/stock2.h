//10.7 ʹ��thisָ��
#ifndef STOCK2_H_
#define STOCK2_H_

#include <iostream>

class Stock
{
private:
	//char company[30];
	char * company;
	int shares;
	double share_val;
	double total_val;
	void set_tot(){total_val = shares * share_val;};
public:
	//Ĭ�Ϲ��캯��
	Stock();
	//���캯��
	Stock(const char * co,int n = 0,double pr = 0.0);
	//copy constructor
	Stock(const Stock & s);
	//��������
	~Stock();
	void buy(int num,double price);
	void sell(int num,double price);
	void update(double price);
	//member overload
	Stock operator= (const Stock & s);
	//void show()const;
	friend std::ostream & operator<< (std::ostream & os,const Stock & s);
	const Stock & topval(const Stock & s)const;
};

#endif