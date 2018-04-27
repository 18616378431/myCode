////15.11 exception class
//#include <iostream>
//#include <cmath>
//#include <string>
//#include "exc_mean3.h"
//
//using namespace std;
//
////function prototypes
//double hmean(double a,double b) throw(bad_hmean);
//double gmean(double a,double b) throw(bad_gmean);
//
//int main()
//{
//	
//
//	double x,y,z;
//	cout << "Enter two numbers:";
//	while(cin >> x >> y)
//	{
//		try
//		{
//			z = hmean(x,y);
//			cout << "Harmonic mean of " << x << " and " << y
//				<< " is " << z << endl;
//			cout << "Geometric mean of " << x << " and " << y
//				<< " is " << gmean(x,y) << endl;
//			cout << "Enter next set of numbers <q to quit>:";
//		}
//		catch(bad_hmean & bg)
//		{
//			bg.mesg();
//			cout << "Try again\n";
//			break;
//		}
//		catch(bad_gmean & hg)
//		{
//			hg.mesg();
//			cout << "Values used:" << hg.v1 << "," << hg.v2 << endl;
//			cout << "Sorry,you don't get to play any more.\n";
//			break;
//		}
//	}
//	cout << "Bye.\n";
//	
//	return 0;
//}
//double hmean(double a,double b) throw(bad_hmean)
//{
//	if(a == -b)
//		throw bad_hmean(string(__FUNCTION__),a,b);
//	return 2 * a * b / (a + b);
//}
//double gmean(double a,double b) throw(bad_gmean)
//{
//	if(a < 0 || b < 0)
//		throw bad_gmean(string(__FUNCTION__),a,b);
//	return std::sqrt(a * b);
//}