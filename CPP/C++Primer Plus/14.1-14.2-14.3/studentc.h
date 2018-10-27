//14.1 has-a
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;//contained object
	ArrayDb scores;
	std::ostream & array_out(std::ostream & os)const;
public:
	//construct
	Student():name("NUll Student"),scores(){}
	Student(const std::string & s):name(s),scores(){}
	explicit Student(int n):name("NUlly"),scores(n){}
	Student(const std::string & s,int n):name(s),scores(n){}
	Student(const std::string & s,ArrayDb a):name(s),scores(a){}
	Student(const char * s,double * pd,int n):name(s),scores(pd,n){}
	~Student(){}
	//member
	double Average()const;
	const std::string & Name()const;
	double & operator[] (int i);
	double operator[] (int i)const;
	//friends
	//input
	friend std::istream & operator>> (std::istream & is,Student & s);//1 word
	friend std::istream & getline(std::istream & is,Student & s);//1 line
	//output
	friend std::ostream & operator<< (std::ostream & os,const Student & s);
};

#endif