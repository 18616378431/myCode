//14.23 template friend to a template class
#include <iostream>

//template prototypes
template <typename T> void counts();
template <typename T> void report(T &);
//template class
template <typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT & i):item(i){ct++;}
	~HasFriendT(){ct--;}
	friend void counts<TT>();
	friend void report<>(HasFriendT<TT> &);
};
template <typename T>
int HasFriendT<T>::ct = 0;

//template friend functions definitions
template <typename T>
void counts()
{
	std::cout << "template size:" << sizeof(HasFriendT<T>) << std::endl;
	std::cout << "template counts():" << HasFriendT<T>::ct << std::endl;
}
template <typename T>
void report(T & hf)
{
	std::cout << hf.item << std::endl;
}


int main()
{
	using namespace std;

	counts<int>();

	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);

	report(hfi1);
	report(hfi2);
	report(hfdb);

	cout << "count<int>() output:\n";
	counts<int>();

	cout << "counts<double>() output:\n";
	counts<double>();

	return 0;
}