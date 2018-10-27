//16.13 assert
#include <iostream>
#include <iterator>
#include <list>

template <class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t):cutoff(t){}
	bool operator() (const T & v){return v > cutoff;}
};

int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100);
	list<int> yadayada;
	list<int> etcetera;
	int vals[10] = {50,100,90,180,60,210,415,88,188,201};

	yadayada.insert(yadayada.begin(),vals,vals + 10);
	etcetera.insert(etcetera.begin(),vals,vals + 10);
	std::ostream_iterator<int,char> out(cout," ");
	cout << "Original lists:\n";
	copy(yadayada.begin(),yadayada.end(),out);
	cout << endl;
	copy(etcetera.begin(),etcetera.end(),out);
	cout << endl;
	yadayada.remove_if(f100);
	etcetera.remove_if(TooBig<int>(200));
	cout << "Trimmed lists:\n";
	copy(yadayada.begin(),yadayada.end(),out);
	cout << endl;
	copy(etcetera.begin(),etcetera.end(),out);

	return 0;
}
