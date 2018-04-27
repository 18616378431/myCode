//14.19 multiple template args
#include <iostream>
#include <string>

template <class T1,class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	Pair(){}
	Pair(const T1 & aval,const T2 & bval):a(aval),b(bval){}
	T1 & first();
	T2 & second();
	T1 first()const{return a;}
	T2 second()const{return b;}
};
template <class T1,class T2>
T1 & Pair<T1,T2>::first()
{
	return a;
}
template <class T1,class T2>
T2 & Pair<T1,T2>::second()
{
	return b;
}


int main()
{
	using namespace std;
	
	Pair<string,int> ratings[4] = {
		Pair<string,int>("w5",5),
		Pair<string,int>("w4",4),
		Pair<string,int>("w5",5),
		Pair<string,int>("w3",3)
	};
	
	//debug
	cout << "sizeof(ratings)" << sizeof(ratings) << endl;
	cout << "sizeof(Pair<string,int>)" << sizeof(Pair<string,int>) << endl;
	cout << "sizeof(string):" << sizeof(string) << endl;

	int joints = sizeof(ratings) / sizeof(Pair<string,int>);
	cout << "Rating:\tEatery:\n";
	for(int i = 0;i < joints;i++)
		cout << ratings[i].second() << ":\t" << ratings[i].first() << endl;
	cout << "Oops!Revised rating:\n";
	ratings[3].first() = "neww3";
	ratings[3].second() = 6;
	cout << ratings[3].second() << ":\t" << ratings[3].first() << endl;

	return 0;
}