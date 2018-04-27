//11.8 重载其他操作符 程序实现
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
	total = wedding + waxing;//重载+
	total.Show();
	cout << endl;

	cout << "Diff work time = ";
	diff = wedding - waxing;//重载-
	diff.Show();
	cout << endl;
	
	adjusted = total * 1.5;//重载*
	cout << "Adjusted work time = ";
	adjusted.Show();
	cout << endl;

	return 0;
}