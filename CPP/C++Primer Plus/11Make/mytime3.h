//11.10 友元函数重载操作符
#ifndef MYTIME3_H_
#define MYTIME3_H_

#include<iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h,int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0,int m = 0);
	/*Time operator +(const Time & t)const;
	Time operator -(const Time & t)const;
	Time operator *(double n)const;*/

	//friend overload operator
	friend Time operator+ (const Time & t1,const Time & t2);
	friend Time operator- (const Time & t1,const Time & t2);
	friend Time operator* (double n,const Time & t);
	//内联友元函数
	/*friend Time operator *(double m,const Time & t)
	{
		return t * m;
	}*/
	friend std::ostream & operator <<(std::ostream & os,const Time & t);
};

#endif