//4.
//a.已实现 port.h port.cpp
//b.赋值操作符不能继承、构造函数不能继承、复制构造函数不能继承、
//析构函数不能继承、友元不能继承
//c.友元不是成员函数不能声明为虚拟的、赋值操作符声明为虚拟的,
//派生类和基类参数不同将隐藏基类版本
//d.已实现 port.h port.cpp
#include <iostream>
#include "port.h"

int main()
{
	using namespace std;

	Port p1("w1","red",10);
	VintagePort vp1("w2","blue",20,"wjk",1990);
	Port *pp;

	p1.Show();
	pp = &p1;
	pp->Show();
	cout << p1 << endl;
	
	cout << "#######################\n";

	vp1.Show();
	pp = &vp1;
	pp->Show();
	cout << vp1 << endl;

	cout << "#######################\n";

	p1 += 100;
	p1.Show();

	vp1 += 200;
	vp1.Show();

	cout << "#######################\n";

	VintagePort vp2;
	vp2 = vp1;
	vp2.Show();

	VintagePort vp3 = vp1;
	vp3.Show();

	cout << "#######################\n";





	

	
	
	

	



	return 0;
}