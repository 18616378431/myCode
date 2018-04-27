////模板具体化
//#include<iostream>
//#include<cstring> strlen()
//
//using namespace std;
//
//template <class T>
//T maxn(T * a,int n);
//
////模板具体化之前要有相应模板的常规声明
//template <> char * maxn(char * str[],int n);
//
//int main()
//{
//	int a[6] = {9,2,1,5,6,4};
//	double b[4] = {2.2,3.3,4.4,7.7};
//
//	cout << maxn(a,6) << endl;
//	cout << maxn(b,4) << endl;
//
//	char *str[5] = {
//		"abcdefg",
//		"abcde",
//		"dddd",
//		"eeeeeee",
//		"ll"
//	};
//	int n = sizeof(str)/sizeof(char *);
//	
//	cout << maxn(str,n) << endl;
//	return 0;
//}
//template <class T>
//T maxn(T * a,int n)
//{
//	T temp = a[0];
//	for(int i = 1;i < n;i++)
//		if(temp < a[i])
//			temp = a[i];
//	return temp;
//}
////模板具体化
//template <> char * maxn(char * str[],int n)
//{
//	char * temp;
//	int count = 0;
//	int length = 0;
//	for(int i = n - 1; i >= 0;i--)
//	{
//		length = strlen(str[i]);
//		if(length >= count)
//		{
//			temp = str[i];
//			count = length;
//		}
//	}
//	return temp;
//}