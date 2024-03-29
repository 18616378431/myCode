//11.8 重载其他操作符 定义
#include<iostream>
#include"mytime2.h"

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
Time Time::operator +(const Time & t)const
{
	Time sum;

	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
}
Time Time::operator -(const Time & t)const
{
	Time diff;
	int tot1,tot2;

	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;

	return diff;
}
Time Time::operator *(double n)const
{
	Time result;

	long total_minutes = minutes * n + hours * 60 * n;
	result.minutes = total_minutes % 60;
	result.hours = total_minutes / 60;

	return result;
}
void Time::Show()const
{
	std::cout << hours <<  "hours," << minutes << "minutes" << std::endl;
}