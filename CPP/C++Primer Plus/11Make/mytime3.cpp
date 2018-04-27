//4.Time类友元重载操作符
#include<iostream>
#include"mytime3.h"

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h,int m /* = 0 */)
{
	hours = h;
	minutes = m;
}
void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::Reset(int h /* = 0 */,int m /* = 0 */)
{
	hours = h;
	minutes = m;
}
//Time Time::operator +(const Time & t)const
//{
//	Time sum;
//	sum.minutes = minutes + t.minutes;
//	sum.hours = hours + t.hours + sum.minutes / 60;
//	sum.minutes %= 60;
//	return sum;
//}
//Time Time::operator -(const Time & t)const
//{
//	Time diff;
//	int tot1,tot2;
//	tot1 = t.minutes + 60 * t.hours;
//	tot2 = minutes + 60 * hours;
//	diff.hours = (tot2 - tot1) / 60;
//	diff.minutes = (tot2 - tot1) % 60;
//	return diff;
//}
//Time Time::operator *(double mult)const
//{
//	Time result;
//	long totalminutes = minutes * mult + 60 * hours * mult;
//	result.hours = totalminutes / 60;
//	result.minutes = totalminutes % 60;
//	return result;
//}
Time operator+ (const Time & t1,const Time & t2)
{
	Time sum;
	
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
}
Time operator- (const Time & t1,const Time & t2)
{
	Time diff;
	int tot1,tot2;

	tot1 = t1.minutes + t1.hours * 60;
	tot2 = t2.minutes + t2.hours * 60;
	diff.hours = (tot1 - tot2) / 60;
	diff.minutes = (tot1 - tot2) % 60;

	return diff;
}
Time operator* (double n,const Time & t)
{
	Time result;
	long totalMin = t.minutes * n + t.hours * 60 * n;
		
	result.hours = totalMin / 60;
	result.minutes = totalMin % 60;

	return result;
}
std::ostream & operator <<(std::ostream & os,const Time & t)
{
	os << t.hours << "hours," << t.minutes << "minutes";
	return os;
}