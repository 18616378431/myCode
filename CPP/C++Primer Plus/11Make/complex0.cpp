//7. ¸´Êý
#include<iostream>
#include"complex0.h"

Complex::Complex()
{
	real = virtual_val = 0.0;
}
Complex::Complex(double r,double v)
{
	real = r;
	virtual_val = v;
}
Complex::~Complex()
{
	
}
//overload
Complex Complex::operator+ (const Complex & c)const
{
	return Complex(real + c.real,virtual_val + c.virtual_val);
}
Complex Complex::operator- (const Complex & c)const
{
	return Complex(real - c.real,virtual_val - c.virtual_val);
}
Complex Complex::operator* (const Complex & c)const
{
	return Complex((real * c.real - virtual_val * c.virtual_val),(real * c.virtual_val + virtual_val * c.real));
}
//friend
std::ostream & operator<< (std::ostream & os,const Complex & c)
{
	os << "(" << c.real << "," << c.virtual_val << "i)" << std::endl;
	return os;
}
std::istream & operator>> (std::istream & is,Complex & c)
{
	std::cout << "real:";
	is >> c.real;
	std::cout << "virtual_val:";
	is >> c.virtual_val;
	return is;
}