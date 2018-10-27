////1.定义文件
//#include <iostream>
//#include "1.h"
//
////base class
//Cd::Cd()
//{
//	std::strncpy(performers,"Default",50);
//	std::strncpy(label,"Default",20);
//	selections = 0;
//	playtime = 0;
//}
//Cd::Cd(const char * s1,const char * s2,int n,double x)
//{
//	std::strncpy(performers,s1,50);
//	std::strncpy(label,s2,20);
//	selections = n;
//	playtime = x;
//}
//std::ios_base::fmtflags Cd::SetFormat()const
//{
//	//set up ###.## format
//	std::ios_base::fmtflags initialState = std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
//
//	std::cout.setf(std::ios_base::showpoint);
//	std::cout.precision(2);
//
//	return initialState;
//}
//void Cd::Report()const
//{
//	std::ios_base::fmtflags initialState = SetFormat();
//	
//	std::cout << "performers:" << performers
//		<< ",label:" << label
//		<< ",selections:" << selections
//		<< ",playtime:" << playtime << std::endl;
//	
//	std::cout.setf(initialState);
//}
////derived class Classic
//Classic::Classic()
//{
//	std::strncpy(major,"Default",50);
//}
//Classic::Classic(const char * m,const char * s1,const char * s2,int n,double x):Cd(s1,s2,n,x)
//{
//	std::strncpy(major,m,50);
//}
//void Classic::Report()const
//{
//	Cd::Report();
//	std::cout << "major:" << major << std::endl;
//}