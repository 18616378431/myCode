//inheritance,friends,dma
#include <iostream>
#include "dma.h"

int main(int argc,char * argv[])
{
	using namespace std;

	BaseDMA shirt("Portabelly",8);
	LacksDMA balloon("red","Blimpo",4);
	HasDMA map("Mercator","Buffalo Keys",5);

	cout << shirt << endl;
	cout << balloon << endl;
	cout << map << endl;

	LacksDMA balloon2(balloon);
	HasDMA map2;
	map2 = map;

	cout << balloon2 << endl;
	cout << map2 << endl;


	//size of class
	cout << "size of BaseDMA:" << sizeof(BaseDMA) << endl;
	cout << "size of LacksDMA:" << sizeof(LacksDMA) << endl;
	cout << "size of HasDMA:" << sizeof(HasDMA) << endl;
	
	return 0;
}