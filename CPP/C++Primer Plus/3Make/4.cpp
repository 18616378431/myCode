//#include<iostream>
//
//#define HOUR_PER_DAY 24
//#define MIN_PER_HOUR 60
//#define SEC_PER_MIN 60
//
//using namespace std;
//
//int main()
//{
//	long seconds;
//	int day , hour , min , sec;
//	day = hour = min = sec = 0;
//
//	cout << "Enter seconds:31600000" << endl;
//	seconds = 31600000;
//	const int UD = HOUR_PER_DAY * MIN_PER_HOUR * SEC_PER_MIN;
//	while (seconds % UD != seconds)
//	{
//		day++;
//		seconds -= UD;
//	}
//	const int UH = MIN_PER_HOUR * SEC_PER_MIN;
//	while (seconds % UH != seconds)
//	{
//		hour++;
//		seconds -= UH;
//	}
//	const int UM = SEC_PER_MIN;
//	while (seconds % UM != seconds)
//	{
//		min++;
//		seconds -= UM;
//	}
//	sec = seconds;
//	cout << day << endl << hour << endl << min << endl << sec << endl;
//	cout << day * UD + hour * UH + min * UM + sec << endl;
//	return 0;
//}