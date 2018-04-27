//14.20 template member
#include <iostream>

using namespace std;

template <typename T>
class beta
{
private:
	template <typename V>//template member
	class hold
	{
	private:
		V val;
	public:
		hold(V v = 0):val(v){}
		void show()const{cout << val << endl;}
		V Value()const{return val;}
	};
	//template object
	hold<T> q;
	hold<int> n;
public:
	beta(T t,int i):q(t),n(i){}
	template <typename U>//template method
	U blab(U u,T t){return (n.Value() + q.Value()) * u / t;}
	void Show()const{q.show();n.show();}
};

//out class definition template member
template <typename T>
class beta1
{
private:
	template <typename V>//template member
	class hold1;
	//template object
	hold1<T> q;
	hold1<int> n;
public:
	beta1(T t,int i):q(t),n(i){}
	template <typename U>//template method
	U blab1(U u,T t);
	void Show()const{q.show();n.show();}
};
//member definition
template <typename T>
template <typename V>
class beta1<T>::hold1
{
private:
	V val;
public:
	hold1(V v = 0):val(v){}
	void show()const{cout << val << endl;}
	V Value()const{return val;}
};
//member definition
template <typename T>
template <typename U>
U beta1<T>::blab1(U u,T t)
{
	return (n.Value() + q.Value()) * u / t;
}


int main()
{
	beta<double> guy(3.5,3);

	guy.Show();
	cout << guy.blab(10,2.3) << endl;
	cout << "Done\n";

	return 0;
}