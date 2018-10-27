//10.1��������
#include<iostream>
#include<cstring>

class Stock
{
private:
	char company[30];
	int shares;
	double share_val;
	double total_val;
	void set_tot(){total_val = shares * share_val;};
public:
	void acquire(const char * co,int n,double pr);
	void buy(int num,double price);
	void sell(int num,double price);
	void update(double price);
	void show();
};

//10.2���ⶨ���Ա����,λ����ͬ�ļ�
//1.����
void Stock::acquire(const char * co,int n,double pr)
{
	std::strncpy(company,co,29);
	company[29] = '\0';
	if(n < 0)
	{
		std::cerr << "Number of shares can't be negative. "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
	{
		shares = n;
		share_val = pr;
	}
	set_tot();
}
//2.����
void Stock::buy(int num,double price)
{
	if(num < 0)
	{
		std::cerr << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
//3.����
void Stock::sell(int num,double price)
{
	using std::cerr;
	if(num < 0)
	{
		cerr << "Number of shares sole can't be negative. "
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
//4.���¼۸�
void Stock::update(double price)
{
	share_val = price;
	set_tot();
}
//5.��ʽ����
void Stock::show()
{
	using std::cout;
	using std::endl;
	cout << "Company:" << company
		<< " shares:" << shares << endl;
	cout << "Share price:$" << share_val
		<< " Total worth:$" << total_val << endl;
}

//10.3 ʹ�������
int main()
{
	//Ƕ�����ƿռ�,ios_baseλ��std��,
	using std::cout;
	using std::ios_base;

	Stock stock1;
	stock1.acquire("NanoSmart",20,12.50);

	//���������ʽformat,��ʽ��λС��������β��0
	cout.setf(ios_base::fixed);
	//С�������λ
	cout.precision(2);		
	cout.setf(ios_base::showpoint);

	stock1.show();

	stock1.buy(15,18.25);
	stock1.show();

	stock1.sell(400,20.00);
	stock1.show();

	return 0;
}