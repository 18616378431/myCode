////11.17 磅-英石转换类实现
//#include<iostream>
//#include"stonewt6.h"
//
//using std::cout;
//
//Stonewt::Stonewt(double lbs)
//{
//	mode = 'p';
//	stone = (int)lbs / Lbs_per_stn;
//	pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
//	pounds = lbs;
//}
//Stonewt::Stonewt(int stn,double lbs)
//{
//	mode = 'p';
//	stone = stn;
//	pds_left = lbs;
//	pounds = stone * Lbs_per_stn + lbs;
//}
//Stonewt::Stonewt()
//{
//	mode = 'p';
//	pounds = pds_left = stone = 0;
//}
//Stonewt::~Stonewt()
//{
//
//}
////show weight in stone
//void Stonewt::show_stn()const
//{
//	cout << stone << " stone," << pds_left << " pounds\n";
//}
////show weight in pounds
//void Stonewt::show_lbs()const
//{
//	cout << pounds << " pounds\n";
//}
////overload
//Stonewt Stonewt::operator+ (const Stonewt & t)const
//{
//	return Stonewt(pounds + t.pounds);
//}
//Stonewt Stonewt::operator- (const Stonewt & t)const
//{
//	return Stonewt(pounds - t.pounds);
//}
//Stonewt Stonewt::operator* (double n)const
//{
//	return Stonewt(pounds * n);
//}
//Stonewt Stonewt::operator/ (double n)const
//{
//	if(n == 0)
//	{
//		return Stonewt(n);
//	}
//	else
//	{
//		return Stonewt(pounds / n);
//	}
//}
//Stonewt Stonewt::operator% (int n)const
//{
//	if(n == 0)
//	{
//		return Stonewt(n);
//	}
//	else
//	{
//		return Stonewt(int(pounds) % n);
//	}
//}
////重载<操作符,前者小于后者则返回true,否则返回false
//bool Stonewt::operator< (const Stonewt & t)const
//{
//	bool flag = false;
//	if(pounds < t.pounds)
//	{
//		flag = true;
//	}
//	return flag;
//}
////status
//void Stonewt::stone_mode()
//{
//	mode = 's';
//}
//void Stonewt::pounds_mode()
//{
//	mode = 'p';
//}
//std::ostream & operator<< (std::ostream & os,const Stonewt & t)
//{
//	if(t.mode == 'p')
//	{
//		os << t.pounds << " pounds\n";
//	}
//	else if(t.mode == 's')
//	{
//		os << t.stone << " stone," << t.pds_left << " pounds\n";
//	}
//	else
//	{
//		os << t.pounds << " pounds\n";
//	}
//	return os;
//}