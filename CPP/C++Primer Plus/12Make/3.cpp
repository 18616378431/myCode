////3.重新实现第十章stock类
////重载<<操作符并使用动态内存分配
//
//#include<iostream>
//#include"stock2.h"
//
//const int STKS = 4;
//
//int main()
//{
//	using std::cout;
//	using std::ios_base;
//
//	//创建初始化的对象数组
//	Stock stocks[STKS] = {
//		Stock("Nano Smart",12,20.0),
//		Stock("Boffo Objects",200,2.0),
//		Stock("Monolithic Obelisks",130,3.25),
//		Stock("Fleep Enterprises",60,6.5)
//	};
//
//	cout.precision(2);
//	cout.setf(ios_base::fixed,ios_base::floatfield);
//	cout.setf(ios_base::showpoint);
//
//	cout << "Stock holdings:\n";
//	int st;
//	for(st = 0;st < STKS;st++)
//		cout << stocks[st];
//		//stocks[st].show();
//
//	Stock top = stocks[0];//未实现复制构造函数,程序结束执行两次delete,浅复制
//	for(st = 1;st < STKS;st++)
//		top = top.topval(stocks[st]);
//	cout << "\nMost valuable holding:\n";
//	cout << top;
//
//	return 0;
//}