//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	double tvarp;
//	double tax = 0;
//
//	cout << "Enter your tvarp:";
//	while(cin >> tvarp)
//	{
//		if(tvarp < 0)
//			break;
//		if(tvarp <= 5000)
//		{
//			tax = 5000 * 0.00;
//		}
//		else if(tvarp > 5000 && tvarp <= 15000)
//		{
//			tax = 5000 * 0.00 + (tvarp - 5000)*0.10;
//		}
//		else if(tvarp > 15000 && tvarp <= 35000)
//		{
//			tax = 5000 * 0.00 + 10000 * 0.10 + (tvarp - 15000)*0.15;
//		}
//		else if(tvarp > 35000)
//		{
//			tax = 5000 * 0.00 + 10000 * 0.10 + 20000*0.15 + (tvarp - 35000)*0.20;
//		}
//		cout << "tax is " << tax << endl;
//		cout << "Enter your tvarp:";
//	}
//	return 0;
//}