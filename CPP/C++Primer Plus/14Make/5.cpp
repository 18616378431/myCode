//5. MI
//(1)û��ʹ�ö�̬�ڴ����
//(2)��ʹ�û���ָ��ʱ������ȷ������ָ��Ķ��������
//(3)��������ʹ������ͬ���ȵ������๲��һ������ʵ��
//(4)���丸�����Ѿ�����������Ҫ�����ݳ�Ա
//(5)��Ϊ��Ԫ�еĲ����������ÿ���ָ��������
//(6)���뱨��,�����಻��ʵ����
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