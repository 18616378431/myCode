//14.21 template for param
#include <iostream>
#include "stacktp.h"

template <template <typename T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab(){}
	bool push(int a,double x){return s1.push(a) && s2.push(x);}
	bool pop(int & a,double & x){return s1.pop(a) && s2.pop(x);}
};
int main()
{
	using namespace std;
	
	Crab<Stack> nebula;
	//Stack must match template<typename T> class Thing
	int ni;
	double nb;
	cout << "Enter int double pairs,0 0 to quit.\n";
	while(cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if(!nebula.push(ni,nb))
			break;
	}
	while(nebula.pop(ni,nb))
	{
		cout << ni << " " << nb << endl;
	}
	cout << "Done.\n";

	return 0;
}