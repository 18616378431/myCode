//4.
//a.��ʵ�� port.h port.cpp
//b.��ֵ���������ܼ̳С����캯�����ܼ̳С����ƹ��캯�����ܼ̳С�
//�����������ܼ̳С���Ԫ���ܼ̳�
//c.��Ԫ���ǳ�Ա������������Ϊ����ġ���ֵ����������Ϊ�����,
//������ͻ��������ͬ�����ػ���汾
//d.��ʵ�� port.h port.cpp
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