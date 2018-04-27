//10.6 使用类
#include<iostream>
#include"stock1.h"

int main()
{
	using std::cout;
	using std::ios_base;

	//设置输出格式
	cout.precision(2);
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	cout << "Using constructor to create new objects\n";
	//隐式调用构造函数
	Stock stock1("NanoSmart",12,20.0);
	stock1.show();
	
	//显式调用构造函数
	Stock stock2 = Stock("Boffo Objects",2,2.0);
	stock2.show();

	//将一个对象赋值给另一个对象
	cout << "Assingning stock1 to stock2:\n";
	stock2 = stock1;
	cout << "Listing stock1 and stock2:\n";
	stock1.show();
	stock2.show();

	//使用构造函数重置一个对象时会产生临时对象
	cout << "Using a constructor to reset an object\n";
	stock1 = Stock("Nifty Foods",10,50.0);
	cout << "Revised stock1:\n";
	stock1.show();
	cout << "Done\n";

	return 0;
}