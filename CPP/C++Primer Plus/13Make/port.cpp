//4.
#include <iostream>
#include "port.h"

//base class
Port::Port(const char * br,const char * st,int b)
{
	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand,br);
	std::strncpy(style,st,19);
	bottles = b;
}
Port::Port(const Port & p)
{
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand,p.brand);
	std::strncpy(style,p.style,19);
	bottles = p.bottles;
}
Port & Port::operator= (const Port & p)
{
	if(this == &p)
	{
		return *this;
	}
	delete [] brand;
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand,p.brand);
	std::strncpy(style,p.style,19);
	bottles = p.bottles;

	return *this;
}
Port & Port::operator+= (int b)
{
	bottles += b;

	return *this;
}
Port & Port::operator-= (int b)
{
	bottles -= b;

	return *this;
}
void Port::Show()const
{
	std::cout << "Brand:" << brand
		<< "\nStyle:" << style
		<< "\nBottles:" << bottles << std::endl;
}
std::ostream & operator<< (std::ostream & os,const Port & p)
{
	os << p.brand << "," << p.style << "," << p.bottles;

	return os;
}
//derived class
VintagePort::VintagePort():Port()
{
	nickname = new char[1];
	nickname[0] = '\0';
	year = 0;
}
VintagePort::VintagePort(const char * br,const char * st,int b,const char *nn,int y):Port(br,st,b)
{
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname,nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort & v):Port(v)
{
	nickname = new char[std::strlen(v.nickname) + 1];
	std::strcpy(nickname,v.nickname);
	year = v.year;
}
VintagePort & VintagePort::operator= (const VintagePort & v)
{
	if(this == &v)
	{
		return *this;
	}
	Port::operator=(v);
	delete [] nickname;
	nickname = new char[std::strlen(v.nickname) + 1];
	std::strcpy(nickname,v.nickname);
	year = v.year;

	return *this;
}
void VintagePort::Show()const
{
	Port::Show();
	std::cout << "Nickname:" << nickname
		<< "\nYear:" << year << std::endl;
}
std::ostream & operator<< (std::ostream & os,const VintagePort & v)
{
	os << (const Port &)v;
	os << v.nickname << "," << v.year;

	return os;
}