////ʹ��ָ�����䴫������
//#include<iostream>
//
//using namespace std;
//
//const int MAX = 5;
//
//double *fill_array(double * const begin,double * const end);
//void show_array(const double *begin,const double *end);
//void revalue(double r,double * const begin,double * const end);
//
//int main()
//{
//	double properties[MAX];
//	double *new_end = fill_array(properties,properties+MAX);
//	double u;
//	
//	show_array(properties,new_end);
//
//	cin.clear();
//	while(cin.get() != '\n')
//		continue;
//	cin >> u;
//	revalue(u,properties,new_end);
//	show_array(properties,new_end);
//	return 0;
//}
////�������,��ʼ����βָ��ָ�򲻿ɱ�
//double *fill_array(double * const begin,double * const end)
//{
//	double *p = begin;
//	double temp;
//
//	while(p != end && cin >> temp)
//	{
//		if(temp < 0)
//			break;
//		*p++ = temp;
//	}
//	return p;
//}
////��ʾ��������
//void show_array(const double *begin,const double *end)
//{
//	const double *p = begin;
//	cout << "show_array" << endl;
//	while(p != end)
//	{
//		cout << *p++ << endl;
//	}
//}
////�������¸�ֵ
//void revalue(double r,double * const begin,double * const end)
//{
//	double *p = begin;
//
//	while(p != end)
//	{
//		*p *= r;
//		p++;
//	}
//}