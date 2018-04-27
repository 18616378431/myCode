////11章 复习题1 重载操作符
//#include<iostream>
//#include"stonewt.h"
//#include "vector.h"
//
//int main()
//{
//	using namespace std;
//	using VECTOR::Vector;
//	
//	Stonewt poppins(10,8);
//	Stonewt r,x;
//	
//	//1.成员函数重载操作符 obj * double
//	r = poppins * 2;
//	r.show_stn();
//	
//	//4.友元函数重载*操作符 double * obj
//	x = 2 * poppins;
//	x.show_stn();
//
//	//7.类到内置类型的转换
//	Vector result(3,4);
//
//	cout << "VECTOR::Vector to double = " << double(result) << endl;
//
//	return 0;
//}
////2.友元函数与成员函数的区别
////成员函数时类定义的一部分,通过类对象来调用
////成员函数可以隐式访问对象成员而无需使用成员操作符
////友元函数不是类的组成部分,因此被称为直接函数调用
////友元函数不能隐式访问类成员,必须将成员操作符用于传递过来的类对象
//
////3.访问私有成员必须是友元,访问公有成员可以不是友元
//
////5.哪些操作符不能重载
////[1]sizeof
////[2].
////[3].*
////[4]::
////[5]:?
//
////6.重载操作符=、()、[]、->有什么限制
////仅能通过成员函数重载