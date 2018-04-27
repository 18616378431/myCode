//15.10 exception for class
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>
#include <stdexcept>

class bad_hmean:public std::logic_error
{
public:
	bad_hmean(const std::string & _Str):logic_error(_Str){}
};

class bad_gmean:public std::logic_error
{
public:
	bad_gmean(const std::string & _Str):logic_error(_Str){}
};

#endif