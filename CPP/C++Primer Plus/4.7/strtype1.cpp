#include<iostream>
#include<string>

using namespace std;

int main()
{
	char r1[20];
	char r2[20] = "jjjjj";
	string str1;
	string str2 = "sssss";

	cout << "Enter a kind of feline:";
	cin >> r1;
	cout << "Enter another of feline:";
	cin >> str1;
	cout << "Here are some felines:" << endl;
	cout << r1 << " " << r2 << " " << str1 << " " << str2 << endl;
	cout << "The third letter in " << r2 << " is " << r2[2] << endl;
	cout << "The third letter in " << str2 << " is " << str2[2] << endl;
	return 0;
}