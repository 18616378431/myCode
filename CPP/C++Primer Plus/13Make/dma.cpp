//dma class methods
#include <cstring>
#include "dma.h"

//Abstract Base Class
ABC::ABC(const char * f,int l)
{
	fullname = new char[std::strlen(f) + 1];
	std::strcpy(fullname,f);
	level = l;
}
ABC::ABC(const ABC & ab)
{
	fullname = new char[std::strlen(ab.fullname) + 1];
	std::strcpy(fullname,ab.fullname);
	level = ab.level;
}
ABC::~ABC()
{
	delete [] fullname;
}
ABC & ABC::operator= (const ABC & ab)
{
	if(this == &ab)
	{
		return *this;
	}
	delete [] fullname;
	fullname = new char[std::strlen(ab.fullname) + 1];
	std::strcpy(fullname,ab.fullname);
	level = ab.level;
	
	return *this;
}
void ABC::View()const
{
	std::cout << "Fullname:" << fullname
		<< ",Level:" << level << std::endl;
}

//BaseDMA methods
BaseDMA::BaseDMA(const char * l,int r,const char * f,int lv):ABC(f,lv)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label,l);
	rating = r;
}
BaseDMA::BaseDMA(const BaseDMA & rs):ABC(rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label,rs.label);
	rating = rs.rating;
}
BaseDMA::~BaseDMA()
{
	delete [] label;
}
BaseDMA & BaseDMA::operator= (const BaseDMA & rs)
{
	if(this == &rs)
	{
		return *this;
	}
	ABC::operator=(rs);
	delete [] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label,rs.label);
	rating = rs.rating;

	return *this;
}
std::ostream & operator<< (std::ostream & os,const BaseDMA & rs)
{
	os << "Label:" << rs.label << std::endl;
	os << "Rating:" << rs.rating << std::endl;

	return os;
}
void BaseDMA::View()const
{
	ABC::View();
	std::cout << "Label:" << label
		<< ",Rating:" << rating << std::endl;
}
//LacksDMA methods
LacksDMA::LacksDMA(const char * c,const char * f,int l):ABC(f,l)
{
	std::strncpy(color,c,COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
LacksDMA::LacksDMA(const char * c,const ABC & ab):ABC(ab)
{
	std::strncpy(color,c,COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
std::ostream & operator<< (std::ostream & os,const LacksDMA & ls)
{
	os << (BaseDMA &)ls;
	os << "Color:" << ls.color << std::endl;

	return os;
}
void LacksDMA::View()const
{
	ABC::View();
	std::cout << "Color:" << color << std::endl;
}
//HasDMA methods
HasDMA::HasDMA(const char * s,const char * f,int l):ABC(f,l)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style,s);
}
HasDMA::HasDMA(const char * s,const ABC & ab):ABC(ab)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style,s);
}
HasDMA::HasDMA(const HasDMA & hs):ABC(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style,hs.style);
}
HasDMA::~HasDMA()
{
	delete [] style;
}
HasDMA & HasDMA::operator= (const HasDMA & hs)
{
	if(this == &hs)
	{
		return *this;
	}
	ABC::operator=(hs);
	delete [] style;
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style,hs.style);

	return *this;
}
std::ostream & operator<< (std::ostream & os,const HasDMA & ls)
{
	os << (BaseDMA &)ls;
	os << "Style:" << ls.style << std::endl;
	
	return os;
}
void HasDMA::View()const
{
	ABC::View();
	std::cout << "Style:" << style << std::endl;
}