//4.port
#ifndef PORT_H_
#define PORT_H_

#include <iostream>
#include <cstring>

//base class
class Port
{
private:
	char * brand;
	char style[20];
	int bottles;
public:
	Port(const char * br = "none",const char * st = "none",int b = 0);
	Port(const Port & p);
	virtual ~Port(){delete [] brand;}
	Port & operator= (const Port & p);
	Port & operator+= (int b);
	Port & operator-= (int b);
	int BottleCount()const{return bottles;}
	virtual void Show()const;
	friend std::ostream & operator<< (std::ostream & os,const Port & p);
};
//derived class
class VintagePort:public Port
{
private:
	char * nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char * br,const char * st,int b,const char *nn,int y);
	VintagePort(const VintagePort & v);
	~VintagePort(){delete [] nickname;}
	VintagePort & operator= (const VintagePort & v);
	void Show()const;
	friend std::ostream & operator<< (std::ostream & os,const VintagePort & v);
};


#endif