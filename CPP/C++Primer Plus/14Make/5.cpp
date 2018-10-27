//5. MI
//(1)没有使用动态内存分配
//(2)在使用基类指针时可以正确访问其指向的对象的内容
//(3)虚基类可以使具有相同祖先的派生类共享一个基类实例
//(4)在其父类中已经定义了其需要的数据成员
//(5)因为友元中的参数基类引用可以指向派生类
//(6)编译报错,抽象类不可实例化
#include <iostream>
#include "emp.h"

int main()
{
	using namespace std;
	
	employee em("Trip","Harris","Thumper");
	//cout << "cout:" << em << endl;
	em.ShowAll();

	manager ma("Amorphia","Spindragon","Nuancer",5);
	//cout << "cout:" << ma << endl;
	ma.ShowAll();
	
	fink fi("Matt","Oggs","Oiler","Juno Barr");
	//cout << "cout:" << fi << endl;
	fi.ShowAll();

	highfink hf(ma,"Curly Kew");
	hf.ShowAll();

	cout << "Press any key for next phase:\n";
	cin.get();

	highfink hf2;
	hf2.SetAll();

	cout << "Use a abstr_emp * pointer:\n";
	abstr_emp * tri[4] = {&em,&fi,&hf,&hf2};
	for(int i = 0;i < 4;i++)
		tri[i]->ShowAll();

	return 0;
}