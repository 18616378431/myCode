////11ÕÂ ¸´Ï°Ìâ1 ÖØÔØ²Ù×÷·û
//#include<iostream>
//#include"stonewt.h"
//
//using std::cout;
//
//Stonewt::Stonewt(double lbs)
//{
//	stone = int(lbs) / Lbs_per_stn;
//	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
//	pounds = lbs;
//}
//Stonewt::Stonewt(int stn,double lbs)
//{
//	stone = stn;
//	pds_left = lbs;
//	pounds = stn * Lbs_per_stn + lbs;
//}
//Stonewt::Stonewt()
//{
//	pounds = pds_left = stone = 0;
//}
//Stonewt::~Stonewt()
//{
//
//}
//void Stonewt::show_stn()const
//{
//	cout << stone << " stone," << pds_left << " pounds\n";
//}
//void Stonewt::show_lbs()const
//{
//	cout << pounds << " pounds\n";
//}
////overload
//Stonewt Stonewt::operator* (double n)const
//{
//	return Stonewt(n * pounds);
//}
////friend
//Stonewt operator* (double n,const Stonewt & st)
//{
//	return st * n;
//}
