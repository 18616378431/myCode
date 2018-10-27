//inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_

#include <iostream>

//Base class using DMA
class BaseDMA
{
private:
	char *label;
	int rating;
public:
	BaseDMA(const char *l = "null",int r = 0);
	BaseDMA(const BaseDMA & rs);
	virtual ~BaseDMA();
	BaseDMA & operator= (const BaseDMA & rs);
	friend std::ostream & operator<< (std::ostream & os,const BaseDMA & rs);
};
//derived class without DMA,no destructor
//uses implicit copy constructor
//uses implicit assignment operator
class LacksDMA:public BaseDMA
{
private:
	enum{COL_LEN=40};
	char color[COL_LEN];
public:
	LacksDMA(const char * c = "blank",const char * l = "null",int r = 0);
	LacksDMA(const char * c,const BaseDMA & rs);
	//overload friend
	friend std::ostream & operator<< (std::ostream & os,const LacksDMA & ls);
};
//derived class with DMA
class HasDMA:public BaseDMA
{
private:
	char * style;
public:
	HasDMA(const char * s = "none",const char * l = "null",int r = 0);
	HasDMA(const char * s,const BaseDMA & rs);
	HasDMA(const HasDMA & hs);
	virtual ~HasDMA();
	//overload friend
	HasDMA & operator= (const HasDMA & hs);
	friend std::ostream & operator<< (std::ostream & os,const HasDMA & hs);
};


#endif