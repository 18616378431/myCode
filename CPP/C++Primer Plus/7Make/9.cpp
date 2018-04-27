////函数指针数组
//#include<iostream>
//
//using namespace std;
//
//double add(double a,double b);
//double minus(double a,double b);
//double ride(double a,double b);
//double except(double a,double b);
//
//double calculate(double x,double y,double (*pf)(double,double));
//
//int main()
//{
//	double x,y;
//	double (*pf[4])(double,double) = {add,minus,ride,except};
//
//	while(cin >> x >> y)
//	{
//		/*double q = calculate(x,y,add);
//		double p = calculate(x,y,minus);
//		double r = calculate(x,y,ride);
//		double e = calculate(x,y,except);*/
//
//		//循环遍历函数指针数组
//		for(int i = 0;i < 4;i++)
//		{
//			double q = calculate(x,y,pf[i]);
//			cout << q << endl;
//		}
//	}
//
//	return 0;
//}
////+
//double add(double a,double b)
//{
//	return a+b;
//}
////-
//double minus(double a,double b)
//{
//	return a-b;
//}
////*
//double ride(double a,double b)
//{
//	return a*b;
//}
//// /
//double except(double a,double b)
//{
//	if(b == 0)
//		return 1;
//	return a/b;
//}
//double calculate(double x,double y,double (*pf)(double,double))
//{
//	return (*pf)(x,y);
//}