////1. ╩ьнд otto,tot
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//bool check(string & s);
//
//int main()
//{
//	string words;
//	cout << "Enter a word to check(quit to quit):";
//	while(cin >> words && words != "quit")
//	{
//		if(check(words))
//			cout << "Yes!\n";
//		else
//			cout << "No!\n";
//		cout << "Enter a word to check(quit to quit):";
//	}
//	cout << "Done\n";
//
//	return 0;
//}
//bool check(string & s)
//{
//	string temp = s;
//	
//	reverse(s.begin(),s.end());
//
//	cout << temp << "-" << s << endl;
//
//	if(temp == s)
//		return true;
//	else
//		return false;
//}