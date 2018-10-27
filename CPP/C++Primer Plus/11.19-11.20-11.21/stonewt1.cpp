//11.20 类转换为内置类型转换函数实现
#include<iostream>
#include"stonewt1.h"

using std::cout;

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}
Stonewt::Stonewt(int stn,double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt()
{
	pounds = pds_left = stone = 0;
}
Stonewt::~Stonewt()
{

}
void Stonewt::show_stn()const
{
	cout << stone << " stone," << pds_left << " pounds\n";
}
void Stonewt::show_lbs()const
{
	cout << pounds << " pounds\n";
}
//conversion functions
Stonewt::operator int()const
{
	return int(pounds + 0.5);
}
Stonewt::operator double()const
{
	return pounds;
}