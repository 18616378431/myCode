//1.pratice
#ifndef MAKE1_H_
#define MAKE1_H_

#include <iostream>
#include <string>
#include <valarray>
#include <utility>
#include "pairs.h"

typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt,ArrayInt> PairArray;

class Wine:private std::string,private PairArray
{
private:
	int years;
public:
	Wine():std::string("none"),years(0){}
	Wine(const char * l,int y,const int yr[],const int bot[]);
	Wine(const char * l,int y);
	void GetBottles();
	const std::string & Label()const;
	int sum()const;
	void Show()const;
};

#endif