//12.1 string simple implement
#include<iostream>

#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad
{
private:
	char * str;//pointer to string
	int len;//length of string
	static int num_strings;//number of objects
public:
	StringBad(const char * s);//ctor
	StringBad();//default ctor
	~StringBad();//dtor
	//friend
	friend std::ostream & operator<< (std::ostream & os,const StringBad & st);
};

#endif