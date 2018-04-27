//12.5
#include<cstring>
#include"string1.h"

using std::cin;
using std::cout;

//初始化静态类成员
int String::num_strings = 0;

//static method
int String::HowMany()
{
	return num_strings;
}

//class method
String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str,s);
	num_strings++;
}
String::String()
{
	len = 1;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
//-copy constructor-
String::String(const String & st)
{
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str,st.str);
	num_strings++;
}
String::~String()
{
	delete [] str;
	num_strings--;
}
//overload member method
//assign a string to a string
String & String::operator= (const String & st)
{
	if(this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str,st.str);
	return *this;
}
//assign a C string to a string
String & String::operator= (const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str,s);
	return *this;
}
//read-write char access for non-const String
char & String::operator[] (int i)
{
	return str[i];
}
const char & String::operator[](int i)const
{
	return str[i];
}
//overload operator friend
bool operator< (const String & st1,const String & st2)
{
	return (std::strcmp(st1.str,st2.str) < 0);
}
bool operator> (const String & st1,const String & st2)
{
	return st2.str < st1.str;
}
bool operator== (const String & st1,const String & st2)
{
	return (std::strcmp(st1.str,st2.str) == 0);
}
//sample string out
ostream & operator<< (ostream & os,const String & st)
{
	os << st.str;
	return os;
}
//quick and dirty string input
istream & operator>> (istream & is,String & st)
{
	char temp[String::CINLIM];
	is.get(temp,String::CINLIM);
	if(is)
		st = temp;
	while(is && is.get() != '\n')
		continue;
	return is;
}