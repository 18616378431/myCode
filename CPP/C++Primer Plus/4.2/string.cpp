#include<iostream>

using namespace std;

int main()
{
	const int SIZE = 15;//·ûºÅ³£Á¿
	char name1[SIZE];
	char name2[SIZE] = "C++owboy!";
	
	cout << "Hello!I'm " << name2 << "!What is your name?" << endl;
	cin >> name1;
	cout << "Well!" << name1 << ",your name has " << strlen(name1) << " letters and stored in an array of " << sizeof(name1) << "bytes." << endl;
	cout << "Your initial is " << name1[0] << endl;
	name2[3] = '\0';
	cout << "Here is the first 3 characters of my name:" << name2 << endl;
	return 0;
}