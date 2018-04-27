////11.12 使用定义了友元函数重载操作符的类定义
//#include<iostream>
//#include"mytime3.h"
//
//int main()
//{
//	using std::cout;
//	using std::endl;
//
//	Time aida(3,35);
//	Time tosca(2,48);
//	Time temp;
//
//	cout << "Aida and Tosca:\n";
//	//友元重载操作符<<
//	cout << aida << ";" << tosca << endl;
//	
//	//友元重载+
//	temp = aida + tosca;
//	cout << "Aida + Tosca:" << temp << endl;
//	
//	//友元重载*
//	temp = 1.17 * aida;
//	cout << "Aida * 1.17:" << temp << endl;
//
//	//友元重载*
//	cout << "10 * tosca:" << 10 * tosca << endl;
//
//	return 0;
//}