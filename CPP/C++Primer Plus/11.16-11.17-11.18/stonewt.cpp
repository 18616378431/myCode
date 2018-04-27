//11.17 磅-英石转换类实现
#include<iostream>
#include"stonewt.h"

using std::cout;

Stonewt::Stonewt(double lbs)
{
	stone = (int)lbs / Lbs_per_stn;
	pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
	pounds = lbs;
}
Stonewt::Stonewt(int stn,double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stone * Lbs_per_stn + lbs;
}
Stonewt::Stonewt()
{
	pounds = pds_left = stone = 0;
}
Stonewt::~Stonewt()
{

}
//show weight in stone
void Stonewt::show_stn()const
{
	cout << stone << " stone," << pds_left << " pounds\n";
}
//show weight in pounds
void Stonewt::show_lbs()const
{
	cout << pounds << " pounds\n";
}