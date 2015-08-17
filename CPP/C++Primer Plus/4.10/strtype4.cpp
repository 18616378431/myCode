#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	char r[20];
	string str;

	cout << "Length of string in r before input:" << strlen(r) << endl;
	cout << "Length of string in str before input:" << str.size() << endl;
	cout << "Enter a line of text:";
	cin.getline(r, 20);
	cout << "You entered " << r << endl;
	cout << "Enter another line of text:";
	getline(cin, str);
	cout << "You entered " << str << endl;
	cout << "Length of string in r after input:" << strlen(r) << endl;
	cout << "Length of string in str after input:" << str.size() << endl;
	return 0;
}