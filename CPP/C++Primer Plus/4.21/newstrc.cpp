#include<iostream>
using namespace std;

struct inflatable{
	char name[20];
	float volume;
	double price;
};

int main()
{
	inflatable * ps = new inflatable;//��̬�����ṹ,Ϊ�ṹ������ڴ�
	cout << "Enter the name of inflatable item:";
	cin.getline(ps->name, 20);
	cout << "Enter the volume in cubic feet:";
	cin >> (*ps).volume;
	cout << "Enter price:";
	cin >> ps->price;
	cout << "Name:" << ps->name << endl;
	cout << "Volume:" << ps->volume << endl;
	cout << "Price:" << ps->price << endl;
	delete ps;
	return 0;
}