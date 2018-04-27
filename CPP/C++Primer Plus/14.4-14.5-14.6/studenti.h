//14.4 private derived
#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <valarray>
#include <string>

class Student:private std::string,private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	//private methods for scores array output
	std::ostream & arr_out(std::ostream & os)const;
public:
	Student():std::string("Null Student"),ArrayDb(){}
	Student(const std::string & s):std::string(s),ArrayDb(){}
	Student(int n):std::string("Null Student"),ArrayDb(n){}
	Student(const std::string & s,int n):std::string(s),ArrayDb(n){}
	Student(const std::string & s,const ArrayDb & a):std::string(s),ArrayDb(a){}
	Student(const char * str,const double * pd,int n):std::string(str),ArrayDb(pd,n){}
	~Student(){}
	double Average()const;
	double & operator[] (int i);
	double operator[] (int i)const;
	const std::string & Name()const;
	//friends input
	friend std::istream & operator>> (std::istream & is,Student & stu);
	friend std::istream & getline(std::istream & is,Student & stu);
	//output
	friend std::ostream & operator<< (std::ostream & os,const Student & stu);

};

#endif