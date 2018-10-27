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

	//���������غ�����ʾ��
	total = coding.operator+ (fixing);
	cout << "coding.operator+ (fixing) = ";
	total.show();
	cout << endl;

	//���������� ��������ʾ��
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