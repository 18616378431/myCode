//12.3 string simple implement
#include<iostream>
#include"strngbad.h"

using std::cout;
using std::endl;

void callme1(StringBad &);//pass by reference
void callme2(StringBad);//pass by value

int main()
{
	StringBad headline1("Celery Stalks at Midnight");
	StringBad headline2("Lettuce Prey");
	StringBad sports("Spinach Leaves Bowl for Dollars");

	cout << "headline1:" << headline1 << endl;
	cout << "headline2:" << headline2 << endl;
	cout << "sports:" << sports << endl;
	cout << endl;

	callme1(headline1);
	cout << "headline1:" << headline1 << endl;

	cout << "address of headline2:" << &headline2 << endl;
	callme2(headline2);
	cout << "headline2:" << headline2 << endl;
	cout << "address of headline2:" << &headline2 << endl;
	cout << endl;

	cout << "Initialize one object to another:\n";
	StringBad sailor = sports;
	cout << "sailor:" << sailor << endl;
	cout << "address of sports:" << &sports << endl;
	cout << "address of sailor:" << &sailor << endl;
	cout << endl;

	cout << "Assign one object to another:\n";
	StringBad knot;
	cout << "address of knot:" << &knot << endl;
	cout << "address of headline1:" << &headline1 << endl;
	knot = headline1;
	cout << "after get value\n";
	cout << "address of knot:" << &knot << endl;
	cout << "address of headline1:" << &headline1 << endl;
	cout << "knot:" << knot << endl;
	cout << endl;
	cout << "End of main()\n";

	return 0;
}
void callme1(StringBad & rsb)
{
	cout << "String pass by reference:";
	cout << "\"" << rsb << "\"\n";
}
void callme2(StringBad sb)
{
	cout << "String pass by value:";
	cout << "\"" << sb << "\"\n";
	cout << "callme2->address of sb:" << &sb << endl;
}