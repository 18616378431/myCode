#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1 = "p123456";
	string s2, s3;
	cout << "You can assign a string object to another:s2 = s1" << endl;
	s2 = s1;
	cout << "s1 :" << s1 << " s2:" << s2 << endl;
	cout << "Your can assign a C-Style string to a string object." << endl;
	cout << "s2 = \"qwertyu\"";
	s2 = "qwertyu";
	cout << "s2:" << s2 << endl;
	cout << "You can concatenate strings: s3 = s1 + s2" << endl;
	s3 = s1 + s2;
	cout << "s3:" << s3 << endl;
	cout << "You can append strings" << endl;
	s1 += s2;
	cout << "s1 += s2 yields s1 = " << s1 << endl;
	s2 += " for a day";
	cout << "s2 += \"for a day\" yields s2 = " << s2 << endl;
	return 0;
}