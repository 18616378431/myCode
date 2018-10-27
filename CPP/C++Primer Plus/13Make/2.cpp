//1.定义文件
#include <iostream>
#include "2.h"

//base class
Cd::Cd()
{
	performers = new char[MAX];
	std::strncpy(performers,"Default",MAX - 1);
	performers[MAX - 1] = '\0';
	
	label = new char[LMAX];
	std::strncpy(label,"Default",LMAX - 1);
	label[LMAX - 1] = '\0';

	selections = 0;
	playtime = 0;
}
Cd::Cd(const char * s1,const char * s2,int n,double x)
{
	performers = new char[MAX];
	std::strncpy(performers,s1,MAX - 1);
	performers[MAX - 1] = '\0';

	label = new char[LMAX];
	std::strncpy(label,s2,LMAX - 1);
	label[LMAX - 1] = '\0';

	selections = n;
	playtime = x;
}
Cd::Cd(const Cd & cs)
{
	int len = std::strlen(cs.performers);
	performers = new char[len + 1];
	std::strncpy(performers,cs.performers,len);
	performers[len] = '\0';
	
	int lenl = std::strlen(cs.label);
	label = new char[lenl + 1];
	std::strncpy(label,cs.label,lenl);
	label[lenl] = '\0';

	selections = cs.selections;
	playtime = cs.playtime;
}
Cd & Cd::operator= (const Cd & cs)
{
	if(this == &cs)
	{
		return *this;
	}
	delete [] performers;
	delete [] label;

	int len = std::strlen(cs.performers);
	performers = new char[len + 1];
	std::strncpy(performers,cs.performers,len);
	performers[len] = '\0';

	int lenl = std::strlen(cs.label);
	label = new char[lenl + 1];
	std::strncpy(label,cs.label,lenl);
	label[lenl] = '\0';

	selections = cs.selections;
	playtime = cs.playtime;
	
	return *this;
}
Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}
std::ios_base::fmtflags Cd::SetFormat()const
{
	//set up ###.## format
	std::ios_base::fmtflags initialState = std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);

	std::cout.setf(std::ios_base::showpoint);
	std::cout.precision(2);

	return initialState;
}
void Cd::Report()const
{
	std::ios_base::fmtflags initialState = SetFormat();
	
	std::cout << "performers:" << performers
		<< ",label:" << label
		<< ",selections:" << selections
		<< ",playtime:" << playtime << std::endl;
	
	std::cout.setf(initialState);
}
//derived class Classic
Classic::Classic()
{
	major = new char[MAX];
	std::strncpy(major,"Default",MAX - 1);
	major[MAX - 1] = '\0';
}
Classic::Classic(const char * m,const char * s1,const char * s2,int n,double x):Cd(s1,s2,n,x)
{
	major = new char[MAX];
	std::strncpy(major,m,MAX - 1);
	major[MAX - 1] = '\0';
}
Classic::Classic(const Classic & cs):Cd(cs)
{
	int len = std::strlen(cs.major);
	major = new char[len + 1];
	std::strncpy(major,cs.major,len);
	major[len] = '\0';
}
Classic & Classic::operator= (const Classic & cs)
{
	if(this == &cs)
	{
		return *this;
	}
	delete [] major;
	Cd::operator= (cs);

	int len = std::strlen(cs.major);
	major = new char[len + 1];
	std::strncpy(major,cs.major,len);
	major[len] = '\0';
	
	return *this;
}
Classic::~Classic()
{
	delete [] major;
}
void Classic::Report()const
{
	Cd::Report();
	std::cout << "major:" << major << std::endl;
}