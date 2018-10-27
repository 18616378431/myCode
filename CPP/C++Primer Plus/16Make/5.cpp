////5. reduce tempalte
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//template <typename T>
//size_t reduce(T ar[],int n);
//
//int main()
//{
//	long arr[] = {9,3,2,1,2,7,5};
//	int origin_len = sizeof(arr) / sizeof(long);
//	ostream_iterator<long,char> out(cout," ");
//
//	cout << "Original ar length:" << origin_len << endl;
//	cout << "Original ar contents:\n";
//	copy(arr,arr + origin_len,out);
//	cout << endl;
//
//	size_t length = reduce(arr,sizeof(arr) / sizeof(long));
//	cout << "Now ar length:" << length << endl;
//	cout << "Now ar contents:\n";
//	copy(arr,arr + length,out);
//	cout << endl;
//	
//	string sarr[] = {"hello","world","thank","map","key","map"};
//	int sorigin_len = sizeof(sarr) / sizeof(string);
//	ostream_iterator<string,char> sout(cout," ");
//
//	cout << "String original length:" << sorigin_len << endl;
//	cout << "String original contents:\n";
//	copy(sarr,sarr + sorigin_len,sout);
//	cout << endl;
//
//	size_t slength = reduce(sarr,sorigin_len);
//	cout << "Now string sarr length:" << slength << endl;
//	cout << "Now string sarr contents:\n";
//	copy(sarr,sarr + slength,sout);
//	cout << endl;
//
//	return 0;
//}
//
//template <typename T>
//size_t reduce(T ar[],int n)
//{
//	vector<T> temp(ar,ar + n);
//	sort(temp.begin(),temp.end());
//	vector<T>::iterator it = unique(temp.begin(),temp.end());
//	
//	if(it != temp.end())
//	{
//		temp.erase(it,temp.end());
//	}
//	for(int i = 0;i < n;i++)
//	{
//		if(i < (int)temp.size())
//			ar[i] = temp[i];
//	}
//
//	return temp.size();
//}