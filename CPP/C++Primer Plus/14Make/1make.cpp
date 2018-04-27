////1.make wine valarray and class template
//#include "1make.h"
//
//Wine::Wine(const char * l,int y,const int yr[],const int bot[]):label(l),years(y)
//{
//	std::valarray<int> a1(years);
//	std::valarray<int> a2(years);
//	for(int i = 0;i < years;i++)
//	{
//		a1[i] = yr[i];
//		a2[i] = bot[i];
//	}
//	pa = std::make_pair(a1,a2);
//}
//Wine::Wine(const char * l,int y):label(l),years(y)
//{
//	std::valarray<int> a1(years);
//	std::valarray<int> a2(years);
//	pa = std::make_pair(a1,a2);
//}
//void Wine::GetBottles()
//{
//	std::valarray<int> a1(pa.first.size());
//	std::valarray<int> a2(pa.second.size());
//	std::cout << "Enter " << label << " for " << years << std::endl;
//	for(int i = 0;i < years;i++)
//	{
//		std::cout << "Enter year:";
//		std::cin >> a1[i];
//		std::cout << "Enter bottles:";
//		std::cin >> a2[i];
//	}
//	pa = std::make_pair(a1,a2);
//}
//const std::string & Wine::Label()const
//{
//	return label;
//}
//int Wine::sum()const
//{
//	return pa.second.sum();
//}
//void Wine::Show()const
//{
//	std::cout << "Wine:" << label << std::endl;
//	std::cout << "\tYear\tBottles\n";
//	for(int i = 0;i < years;i++)
//	{
//		std::cout << "\t" << pa.first[i] << "\t" << pa.second[i] << std::endl;
//	}
//}