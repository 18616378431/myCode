//16.10 list
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	list<int> one(5,2);
	int stuff[5] ={1,2,4,8,6};
	list<int> two;
	two.insert(two.begin(),stuff,stuff + 5);
	int more[6] = {6,4,2,4,6,5};
	list<int> three(two);
	three.insert(three.begin(),more,more + 6);

	cout << "list one:";
	ostream_iterator<int,char> out(cout," ");
	copy(one.begin(),one.end(),out);
	cout << endl << "list two:";
	copy(two.begin(),two.end(),out);
	cout << endl << "list three:";
	copy(three.begin(),three.end(),out);
	three.remove(2);
	cout << endl << "list three minus 2s:";
	copy(three.begin(),three.end(),out);
	three.splice(three.begin(),one);
	cout << endl << "list three after splice:";
	copy(three.begin(),three.end(),out);
	cout << endl << "list one:";
	copy(one.begin(),one.end(),out);
	three.unique();
	cout << endl << "list three after unique:";
	copy(three.begin(),three.end(),out);
	three.sort();
	three.unique();
	cout << endl << "list three after sort & unique:";
	copy(three.begin(),three.end(),out);
	two.sort();
	three.merge(two);
	cout << endl << "Sorted two merged into three:";
	copy(three.begin(),three.end(),out);
	cout << endl;

	return 0;
}