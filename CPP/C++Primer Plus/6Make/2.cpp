//#include<iostream>
//
//using namespace std;
//
//const int MAX = 10;
//
//int main()
//{
//	double donation[MAX];
//	int i = 0;
//	double sum = 0.0;
//	int gt = 0;
//	double avg = 0.0;
//
//	cout << "Enter float numbers:";
//	while(i < MAX && cin >> donation[i])
//	{
//		sum += donation[i++];
//		if(i < MAX)
//			cout << "Enter float numbers:";
//	}
//	avg = sum / i;
//	for(int j = 0;j < i;j++)
//	{
//		if(donation[j] > avg)
//			gt++;
//	}
//	cout << "Average is " << avg << " and gt is " << gt << endl;
//	return 0;
//}