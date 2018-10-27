#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow()
{
	std::strcpy(name,"Init");
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}
Cow::Cow(const char * nm,const char * ho,double wt)
{
	int holen = std::strlen(ho);
	std::strcpy(name,nm);
	hobby = new char[holen + 1];
	std::strcpy(hobby,ho);
	hobby[holen] = '\0';
	weight = wt;
}
Cow::Cow(const Cow & c)
{	
	int holen = std::strlen(c.hobby);
	std::strcpy(name,c.name);
	hobby = new char[holen + 1];
	std::strcpy(hobby,c.hobby);
	hobby[holen] = '\0';
	weight = c.weight;
}
Cow::~Cow()
{
	delete [] hobby;
}
Cow & Cow::operator= (const Cow & c)
{
	if(this == &c)
		return *this;
	int holen = std::strlen(c.hobby);
	std::strcpy(name,c.name);
	delete [] hobby;
	hobby = new char[holen + 1];
	std::strcpy(hobby,c.hobby);
	hobby[holen] = '\0';
	weight = c.weight;
	return *this;
}
void Cow::showCow()const
{
	std::cout << name << hobby << weight << std::endl;
}