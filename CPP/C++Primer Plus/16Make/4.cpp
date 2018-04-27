////4. reduce
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int reduce(long ar[],int n);
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
//	int length = reduce(arr,sizeof(arr) / sizeof(long));
//	cout << "Now ar length:" << origin_len << endl;
//	cout << "Now ar contents:\n";
//	copy(arr,arr + length,out);
//	cout << endl;
//
//
//	return 0;
//}
//
//int reduce(long ar[],int n)
//{
//	vector<long> temp(ar,ar + n);
//	sort(temp.begin(),temp.end());
//	vector<long>::iterator it = unique(temp.begin(),temp.end());
//	
//	if(it != temp.end())
//	{
//		temp.erase(it,temp.end());
//	}
//	for(int i = 0;i < n;i++)
//	{
//		if(i < (int)temp.size())
//			ar[i] = temp[i];
//		else
//			ar[i] = 0;
//	}
//
//	return temp.size();
//}