//11.8 �������������� ����ʵ��
#include<iostream>
#include"mytime2.h"

int main()
{
	using namespace std;

	Time wedding(4,35);
	Time waxing(2,47);
	Time total;
	Time diff;
	Time adjusted;

	cout << "Wedding time = ";
	wedding.Show();
	cout << endl;

	cout << "Waxing time = ";
	waxing.Show();
	cout << endl;

	cout << "Total work time = ";
	total = wedding + waxing;//����+
	total.Show();
	cout << endl;

	cout << "Diff work time = ";
	diff = wedding - waxing;//����-
	diff.Show();
	cout << endl;
	
	adjusted = total * 1.5;//����*
	cout << "Adjusted work time = ";
	adjusted.Show();
	cout << endl;

	return 0;
}