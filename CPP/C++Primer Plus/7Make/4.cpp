///*�����Ʊ�н�����*/
//#include<iostream>
//
//using namespace std;
//
//long double probabily(unsigned int numbers,unsigned int picks);
//
//int main()
//{
//	unsigned int total,choice;
//
//	cout << "Enter total and choice:";
//	while(cin >> total >> choice && choice < total)
//	{
//		cout << "You have one chance in ";
//		cout << probabily(total,choice)*(27.0/1.0);
//		cout << " of winning\n";
//		cout << "Enter total and choice:";
//	}
//	return 0;
//}
///*����numbers������ѡȡpicks����ȫ���н�����*/
//long double probabily(unsigned int numbers,unsigned int picks)
//{
//	long double result = 1.0;
//	long double n;
//	unsigned int p;
//
//	for(n = numbers,p = picks;p > 0;n--,p--)
//	{
//		result = result * n / p;
//	}
//	return result;
//}