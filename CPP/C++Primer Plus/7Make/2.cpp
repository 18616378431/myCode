///*ʹ������ָ����л�ȡ����ʾ����ֵ*/
//#include<iostream>
//
//using namespace std;
//
//const int SIZE = 10;
//
//void getValue(double *pa,int size);
//void display(const double *pa,int size);
//double getAvg(const double *pa,int size);
//
//int main()
//{
//	double golf[SIZE];
//
//	getValue(golf,SIZE);
//	display(golf,SIZE);
//	cout << "Avg is " << getAvg(golf,SIZE) << endl;
//	return 0;
//}
///*��������ֵ*/
//void getValue(double *pa,int size)
//{
//	double temp;
//	int count = 0;
//
//	cout << "Enter an integer number:";
//	while(count < size && cin >> temp)
//	{
//		*pa = temp;
//		pa++;
//		count++;
//		if(count < size)
//			cout << "Enter an integer number:";
//	}
//}
///*��ʾ����ֵ*/
//void display(const double *pa,int size)
//{
//	int count = 0;
//
//	cout << "Show arr value:" << endl;
//	while(count < size)
//	{
//		cout << *pa << endl;
//		count++;
//		pa++;
//	}
//}
///*��������ƽ��ֵ*/
//double getAvg(const double *pa,int size)
//{
//	double sum = 0;
//	int count = 0;
//	
//	while(count++ < size)
//	{
//		sum += *pa;
//		pa++;
//	}
//	return sum/size;
//}