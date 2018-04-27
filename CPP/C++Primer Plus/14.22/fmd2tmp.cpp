//14.22 non-template friend
#include <iostream>

using namespace std;

template <class T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i):item(i){ct++;}
	~HasFriend(){ct--;}
	//friend for template class
	friend void counts();
	friend void report(HasFriend<T> &);//with template param
};

//every specialization has its own static data member
template <class T>
int HasFriend<T>::ct = 0;

//non-template friend for all HasFriend<T> classes
void counts()
{
	cout << "int count:" << HasFriend<int>::ct << ";";
	cout << "double count:" << HasFriend<double>::ct << endl;
}
//for int
void report(HasFriend<int> & hf)
{
	cout << "HasFriend<int>:" << hf.item << endl;
}
//for double
void report(HasFriend<double> & hf)
{
	cout << "HasFriend<double>:" << hf.item << endl;
}

int main()
{
	cout << "No objects declared:";
	counts();

	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared:";
	counts();

	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared:";
	counts();

	HasFriend<double> hfdb(10.5);
	cout << "After hfdb declared:";
	counts();

	report(hfi1);
	report(hfi2);
	report(hfdb);

	return 0;
}