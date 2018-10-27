//12.4
#include<iostream>

using std::ostream;
using std::istream;

#ifndef STRING_H_
#define STRING_H_

class String
{
private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;//cin input limit
public:
	//constructor and destructor
	String(const char * s);
	String();
	String(const String & st);//copy constructor
	~String();
	//other method
	int length(){return len;}
	//overload operator
	String & operator= (const String & st);
	String & operator= (const char * s);
	char & operator[] (int i);
	const char & operator[] (int i)const;
	//overload operator friend
	friend bool operator< (const String & st1,const String & st2);
	friend bool operator> (const String & st1,const String & st2);
	friend bool operator== (const String & st1,const String & st2);
	friend ostream & operator<< (ostream & os,const String & st);
	friend istream & operator>> (istream & is,String & st);
	//static function
	static int HowMany();
};

#endif