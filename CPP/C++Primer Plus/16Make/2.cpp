////2. ╩ьнд tolower cctype
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cctype>
//
//using namespace std;
//
//bool check(string & s);
//
//int main()
//{
//	string words;
//	cout << "Enter a word(quit to quit):";
//	while(cin >> words && words != "quit")
//	{
//		if(check(words))
//			cout << "Yes\n";
//		else
//			cout << "No\n";
//		cout << "Enter a word(quit to quit):";
//	}
//	cout << "Done\n";
//
//	return 0;
//}
//bool check(string & s)
//{
//	string::iterator it = s.begin();
//
//	while(it != s.end())
//	{
//		if(!isalpha(*it))
//		{
//			it = s.erase(it);
//			continue;
//		}
//		else
//		{
//			*it = tolower(*it);
//			it++;
//		}
//	}
//	string temp = s;
//	reverse(s.begin(),s.end());
//	
//	cout << temp << "-" << s << endl;
//	if(temp == s)
//		return true;
//	else
//		return false;
//}