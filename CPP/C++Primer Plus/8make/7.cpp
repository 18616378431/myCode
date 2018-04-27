//�޸�8.14 showArray����
//����ģ�� �����������
#include<iostream>

//��������Ԫ���ܺ�
template <typename T>
T showArray(T arr[],int n);//template A

template <typename T>
T showArray(T *arr[],int n);//template B

struct debts{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;

	int things[6] = {1,1,1,1,1,1};
	struct debts mr_E[3] = {
		{"Ima Wolfe",1.1},
		{"Ura Foxe",1.1},
		{"Iby Stout",1.1}
	};
	double *pd[3];

	for(int i = 0;i < 3;i++)
		pd[i] = &mr_E[i].amount;

	cout << "Listing Mr.E's counts of things:\n";
	cout << showArray(things,6) << endl;

	cout << "Listing Mr.E's debts:\n";
	cout << showArray(pd,3) << endl;
	return 0;
}
//template A
template <typename T>
T showArray(T arr[],int n)
{
	using namespace std;
	
	T temp = arr[0];

	cout << "Template A:\n";
	for(int i = 1;i < n;i++)
		temp += arr[i];
	return temp;
}
//template B
template <typename T>
T showArray(T * arr[],int n)
{
	using namespace std;
	
	T temp = *arr[0];

	cout << "Template B:\n";
	for(int i = 1;i < n;i++)
		temp += *arr[i];
	return temp;
}