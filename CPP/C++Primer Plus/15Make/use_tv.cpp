////15.3 friend class
//#include <iostream>
//#include "tv.h"
//
//int main()
//{
//	using namespace std;
//
//	Tv s27;
//	cout << "Initial settings fro 27\" TV:\n";
//	s27.settings();
//	s27.onoff();
//	s27.chanup();
//	cout << "\nAdjusted settings for 27\"TV:\n";
//	s27.settings();
//
//	Remote grey;
//	grey.set_chan(s27,10);
//	grey.volup(s27);
//	grey.volup(s27);
//	cout << "\n27\" settings after using remote:\n";
//	s27.settings();
//	grey.showStatus();
//	s27.changeStatus(grey);
//	grey.showStatus();
//
//	Tv s32(Tv::On);
//	s32.set_mode();
//	grey.set_chan(s32,28);
//	cout << "\n32\" settings:\n";
//	s32.settings();
//
//	return 0;
//}