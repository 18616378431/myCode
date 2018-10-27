//15.10 exception for class
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>
#include <stdexcept>
#include <string>

class bad_hmean:public std::logic_error
{
private:
	double v1;
	double v2;
public:
	bad_hmean(std::string & s,double a = 0,double b = 0):v1(a),v2(b),std::logic_error(s){}
	void mesg();
};
inline void bad_hmean::mesg()
{
	std::cout << what() << "(" << v1 << "," << v2 << "):"
		<< "invalid arguments:a = -b\n";
}

class bad_gmean:public std::logic_error
{
public:
	double v1,v2;
	bad_gmean(std::string & s,double a = 0,double b = 0):v1(a),v2(b),std::logic_error(s){}
	void mesg();
};
inline void bad_gmean::mesg()
{
	std::cout <<  what() << "(" << v1 << "," << v2 << ") arguments should be >= 0\n";
}

#endif