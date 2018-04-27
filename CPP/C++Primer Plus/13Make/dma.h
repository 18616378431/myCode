//inheritance and dynamic memory allocation
//友元函数暂时不用 抽象基类未定义
#ifndef DMA_H_
#define DMA_H_

#include <iostream>

//Abstract base class
class ABC
{
private:
	char * fullname;
	int level;
public:
	ABC(const char * f = "NULL",int l = 0);
	ABC(const ABC & ab);
	ABC & operator= (const ABC & ab);
	virtual ~ABC();
	virtual void View()const = 0;
};

//Base class using DMA
class BaseDMA:public ABC
{
private:
	char *label;
	int rating;
public:
	BaseDMA(const char * l = "null",int r = 0,const char * f = "NULL",int lv = 0);
	BaseDMA(const BaseDMA & rs);
	virtual ~BaseDMA();
	BaseDMA & operator= (const BaseDMA & rs);
	friend std::ostream & operator<< (std::ostream & os,const BaseDMA & rs);
	virtual void View()const;
};
//derived class without DMA,no destructor
//uses implicit copy constructor
//uses implicit assignment operator
class LacksDMA:public ABC
{
private:
	enum{COL_LEN=40};
	char color[COL_LEN];
public:
	LacksDMA(const char * c = "blank",const char * f = "NULL",int l = 0);
	LacksDMA(const char * c,const ABC & ab);
	//overload friend
	friend std::ostream & operator<< (std::ostream & os,const LacksDMA & ls);
	virtual void View()const;
};
//derived class with DMA
class HasDMA:public ABC
{
private:
	char * style;
public:
	HasDMA(const char * s = "none",const char * f = "NULL",int l = 0);
	HasDMA(const char * s,const ABC & ab);
	HasDMA(const HasDMA & hs);
	virtual ~HasDMA();
	//overload friend
	HasDMA & operator= (const HasDMA & hs);
	friend std::ostream & operator<< (std::ostream & os,const HasDMA & hs);
	virtual void View()const;
};


#endif