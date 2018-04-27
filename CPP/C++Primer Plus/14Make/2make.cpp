//1.make wine valarray and class template
#include "2make.h"

Wine::Wine(const char * l,int y,const int yr[],const int bot[]):
	std::string(l),
	years(y),
	PairArray(std::valarray<int>(yr,y),std::valarray<int>(bot,y))
{
}
Wine::Wine(const char * l,int y):
	std::string(l),
	years(y),
	PairArray(std::valarray<int>(y),std::valarray<int>(y))
{
}
void Wine::GetBottles()
{
	std::valarray<int> a1(PairArray::first.size());
	std::valarray<int> a2(PairArray::second.size());
	std::cout << "Enter " << (const std::string &)(*this) << " for " << years << std::endl;
	for(int i = 0;i < years;i++)
	{
		std::cout << "Enter year:";
		std::cin >> a1[i];
		std::cout << "Enter bottles:";
		std::cin >> a2[i];
	}
	(PairArray &)(*this) = std::make_pair(a1,a2);
}
const std::string & Wine::Label()const
{
	return (const std::string &)(*this);
}
int Wine::sum()const
{
	return PairArray::second.sum();
}
void Wine::Show()const
{
	std::cout << "Wine:" << (const std::string &)(*this) << std::endl;
	std::cout << "\tYear\tBottles\n";
	for(int i = 0;i < years;i++)
	{
		std::cout << "\t" << PairArray::first[i] << "\t" << PairArray::second[i] << std::endl;
	}
}