//#include<iostream>
//#include<string>
//
//using namespace std;
//
//typedef struct gp{
//	string name;
//	double money;
//}GP;
//
//void show(GP *p,int n);
//
//int main()
//{
//	int num;
//	cout << "Enter the number you will type in:";
//	cin >> num;
//	GP *p = new GP[num];
//	int i = 0;
//	while(i < num)
//	{
//		cout << "Enter name:";
//		cin >> p[i].name;
//		cout << "Enter money:";
//		cin >> p[i].money;
//		i++;
//	}
//	show(p,num);
//	delete []p;
//	return 0;
//}
//void show(GP *p,int n)
//{
//	cout << "Grand Patrons" << endl;
//	for(int i = 0;i < n;i++)
//	{
//		if(p[i].money >= 10000)
//		{
//			cout << p[i].name << " " << p[i].money << endl;
//		}
//	}
//	cout << "Patrons" << endl;
//	for(int i = 0;i < n;i++)
//	{
//		if(p[i].money < 10000)
//		{
//			cout << p[i].name << " " << p[i].money << endl;
//		}
//	}
//}