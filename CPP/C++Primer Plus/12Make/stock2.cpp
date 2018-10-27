//10.8 使用this指针的实现
#include<iostream>
#include<cstring>
#include"stock2.h"

//默认构造函数
Stock::Stock()
{
	company = new char[1];
	company[0] = '\0';
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
//构造函数
Stock::Stock(const char * co,int n /* = 0 */,double pr /* = 0.0 */)
{
	int len = std::strlen(co);
	company = new char[len + 1];
	std::strcpy(company,co);
	company[len] = '\0';
	if(n < 0)
	{
		std::cerr << "Number of shares can't be negative."
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
//copy constructor
Stock::Stock(const Stock & s)
{
	int len = std::strlen(s.company);
	company = new char[len + 1];
	std::strcpy(company,s.company);
	company[len] = '\0';
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
}
//析构函数
Stock::~Stock()
{
	delete [] company;
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
		cerr << "Number of shares sold can't be negative."
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
//void Stock::show()const
//{
//	using std::cout;
//	using std::endl;
//
//	cout << "Company:" << company
//		<< " Shares:" << shares << endl
//		<< " Share Price:$" << share_val
//		<< " Total Worth:$" << total_val << endl;
//}
std::ostream & operator<< (std::ostream & os,const Stock & s)
{
	std::cout << "Company:" << s.company
		<< " Shares:" << s.shares << std::endl
		<< " Share Price:$" << s.share_val
		<< " Total Worth:$" << s.total_val << std::endl;
	return os;
}
const Stock & Stock::topval(const Stock & s)const
{
	if(s.total_val > total_val)
	{
		return s;
	}
	else
	{
		return *this;
	}
}
//overload member function
Stock Stock::operator= (const Stock & s)
{
	Stock temp;
	int len = std::strlen(s.company);
	delete [] temp.company;
	temp.company = new char[len + 1];
	std::strcpy(temp.company,s.company);
	temp.shares = s.shares;
	temp.share_val = s.share_val;
	temp.total_val = s.total_val;
	return temp;
}