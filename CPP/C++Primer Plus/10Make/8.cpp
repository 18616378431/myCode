//8.
#include<iostream>
#include"List.h"

void func(Item & item);

int main()
{
	using namespace std;

	List l;
	
	l.addItem(1);
	l.addItem(2);
	l.addItem(3);
	l.addItem(4);
	l.addItem(5);
	l.show();

	cout << "*2\n";

	void (*pf)(Item & item);
	pf = func;
	l.visit(pf);
	l.show();

	return 0;
}
void func(Item & item)
{
	item *= 2;
}