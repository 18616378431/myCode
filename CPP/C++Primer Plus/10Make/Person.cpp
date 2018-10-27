#include<iostream>
#include<cstring>
#include"Person.h"

Person::Person(const std::string & ln,const char * fn /* = */ )
{
	lname = ln;
	strncpy(fname,fn,LIMIT-1);
	fname[LIMIT - 1] = '\0';
}
void Person::show()const
{
	using std::cout;
	using std::endl;

	cout << "First name:" << fname << ",Last name:" << lname << endl;
}
void Person::FormalShow()const
{
	using std::cout;
	using std::endl;

	cout << "Last name:" << lname << ",First name:" << fname << endl;
}