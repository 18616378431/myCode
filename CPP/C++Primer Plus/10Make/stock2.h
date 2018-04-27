//10.7 ʹ��thisָ��
#ifndef STOCK2_H_
#define STOCK2_H_

class Stock
{
private:
	char company[30];
	int shares;
	double share_val;
	double total_val;
	void set_tot(){total_val = shares * share_val;}
public:
	//Ĭ�Ϲ��캯��
	Stock();
	//���캯��
	Stock(const char * co,int n = 0,double pr = 0.0);
	//��������
	~Stock();
	void buy(int num,double price);
	void sell(int num,double price);
	void update(double price);
	void show()const;
	const Stock & topval(const Stock & s)const;
	//��˾����
	const char * getCompany()const{return company;}
	//���й�Ʊ����
	const int getShares()const{return shares;}
	//��Ʊ�۸�
	const double getShareVal()const{return share_val;}
	//��Ʊ�ܼ۸�
	const double getTotalVal()const{return total_val;}
};

#endif