//14.2 has-a
#include <iostream>
#include "studentc.h"

//public methods
double Student::Average()const
{
	if(scores.size() > 0)
	{
		return scores.sum()/scores.size();
	}
	else
	{
		return 0;
	}
}
const std::string & Student::Name()const
{
	return name;
}
double & Student::operator[] (int i)
{
	return scores[i];
}
double Student::operator[] (int i)const
{
	return scores[i];
}
//private methods
std::ostream & Student::array_out(std::ostream & os)const
{
	int i;
	int lim = scores.size();

	if(lim > 0)
	{
		for(i = 0;i < lim;i++)
		{
			os << scores[i] << " ";
			if(i % 5 == 4)
			{
				os << std::endl;
			}
		}
		if(i % 5 != 0)
		{
			os << std::endl;
		}
	}
	return os;
}
//friends
std::istream & operator>> (std::istream & is,Student & s)
{
	is >> s.name;
	return is;
}
std::istream & getline(std::istream & is,Student & s)
{
	getline(is,s.name);
	return is;
}
std::ostream & operator<< (std::ostream & os,const Student & s)
{
	os << "Scores for " << s.name << ":\n";
	s.array_out(os);
	
	return os;
}