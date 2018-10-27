//10.5 类成员实现文件
#include<iostream>
#include<cstring>
#include"stock1.h"

//默认构造函数
Stock::Stock()
{
	std::cout << "Default constructor called\n";
	std::strcpy(company,"no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
//构造函数
Stock::Stock(const char * co,int n,double pr)
{
	std::cout << "Constructor using " << co << " called\n";
	std::strncpy(company,co,29);
	company[29] = '\0';
	if(n < 0)
	{
		std::cerr << "Number of shares can't be negative:"
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();
}
//析构函数
Stock::~Stock()
{
	std::cout << "Bye," << company << "!\n";
}
void Stock::buy(int num,double price)
{
	if(num < 0)
	{
		std::cerr << "Number of shares purchased can't be negative."
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(int num,double price)
{
	using std::cerr;

	if(num < 0)
	{
		std::cerr << "Number of shares sole can't be negative."
			<< "Transaction is aborted.\n";
	}
	else if(num > shares)
	{
		cerr << "You can't sell more than you have!"
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price)
{
	share_val = price;
	set_tot();
}
void Stock::show()
{
	using std::cout;
	using std::endl;

	cout << "Company:" << company
		<< " Shares:" << shares << endl
		<< " Shares price:$" << share_val
		<< " Total worth:$" << total_val << endl;
}