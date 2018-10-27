////1.∆’Õ®¿‡ºÃ≥–
//#include <iostream>
//#include "1.h"
//
//void Bravo(const Cd & disk);
//
//int main()
//{
//	using namespace std;
//
//	Cd c1("Beatles","Capitol",14,35.5);
//	Classic c2 = Classic("Pinao Sonata in B flat,Fantasia in C",
//		"Alfred Brendel","Philips",2,57.17);
//	Cd *pcd = &c1;
//
//	cout << "Using object directly:\n";
//	c1.Report();//Cd method
//	c2.Report();//Classic method
//	
//	cout << "Using type cd * pointer to objects:\n";
//	pcd->Report();//Cd method
//	pcd = &c2;
//	pcd->Report();//Classic method
//
//	cout << "Calling a function with a Cd reference argument:\n";
//	Bravo(c1);
//	Bravo(c2);
//
//	cout << "Testing assignment:\n";
//	Classic copy;
//	copy = c2;
//	copy.Report();
//
//	return 0;
//}
//void Bravo(const Cd & disk)
//{
//	disk.Report();
//}