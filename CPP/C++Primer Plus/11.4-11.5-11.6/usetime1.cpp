//11.6
#include<iostream>
#include"mytime1.h"

int main()
{
	using std::cout;
	using std::endl;

	Time planning;
	Time coding(2,40);
	Time fixing(5,55);
	Time total;

	cout << "Planning time= ";
	planning.show();
	cout << endl;

	cout << "Coding time = ";
	coding.show();
	cout << endl;

	cout << "Fixing time = ";
	fixing.show();
	cout << endl;

	//操作符重载函数表示法
	total = coding.operator+ (fixing);
	cout << "coding.operator+ (fixing) = ";
	total.show();
	cout << endl;

	//操作符重载 操作符表示法
	total = coding + fixing;
	cout << "coding + fixing = ";
	total.show();
	cout << endl;

	Time morefixing(3,28);
	cout << "Morefixing time = ";
	morefixing.show();
	cout << endl;

	total = morefixing.operator +(total);
	cout << "morefixing.operator +(total) = ";
	total.show();
	cout << endl;

	return 0;
}