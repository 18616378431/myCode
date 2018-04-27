//10.7 使用this指针
#ifndef STOCK2_H_
#define STOCK2_H_

class Stock
{
private:
	char company[30];
	int shares;
	double share_val;
	double total_val;
	void set_tot(){total_val = shares * share_val;};
public:
	//默认构造函数
	Stock();
	//构造函数
	Stock(const char * co,int n = 0,double pr = 0.0);
	//析构函数
	~Stock();
	void buy(int num,double price);
	void sell(int num,double price);
	void update(double price);
	void show()const;
	const Stock & topval(const Stock & s)const;
};

#endif