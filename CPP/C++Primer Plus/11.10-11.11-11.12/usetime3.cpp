//11.12 ʹ�ö�������Ԫ�������ز��������ඨ��
#include<iostream>
#include"mytime3.h"

int main()
{
	using std::cout;
	using std::endl;

	Time aida(3,35);
	Time tosca(2,48);
	Time temp;

	cout << "Aida and Tosca:\n";
	//��Ԫ���ز�����<<
	cout << aida << ";" << tosca << endl;
	
	//��Ա����+
	temp = aida + tosca;
	cout << "Aida + Tosca:" << temp << endl;
	
	//��Ա����*
	temp = aida * 1.17;
	cout << "Aida * 1.17:" << temp << endl;

	//������Ԫ����*
	cout << "10 * tosca:" << 10 * tosca << endl;

	return 0;
}