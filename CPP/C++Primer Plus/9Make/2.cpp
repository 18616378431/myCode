////使用本地静态变量
//#include<iostream>
//#include<string>
//
//void strcount(const std::string & str);
//
//int main()
//{
//	using namespace std;
//
//	string input;
//
//	cout << "Enter a line:";
//	getline(cin,input);
//	while(input != "")
//	{
//		strcount(input);
//		cout << "Enter a line(empty line to quit):";
//		getline(cin,input);
//	}
//	return 0;
//}
//void strcount(const std::string & str)
//{
//	using namespace std;
//
//	static int total = 0;
//	
//	total += (int)str.length();
//
//	cout << "\"" << str << "\" contains ";
//	cout << str.length() << " characters,";
//	cout << total << " characters total\n";
//}