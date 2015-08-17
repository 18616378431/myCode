#include<iostream>
#include<string>//string类
#include<cstring>//字符串处理

using namespace std;

int main()
{
	char r1[20];
	char r2[20] = "123";
	string str1;
	string str2 = "qwer";

	//合并string对象和字符数组
	str1 = str2;
	strcpy_s(r1, r2);
	//附加string对象和字符数组
	str1 += "pasdfg";
	strcat_s(r1, "yuio");
	//string对象的长度和C风格字符串的长度
	int lenStr = str1.size();
	int lenCharArray = strlen(r1);
	cout << "The string " << str1 << " contains " << lenStr << " letters." << endl;
	cout << "The string " << r1 << " contains " << lenCharArray << " letters." << endl;
	return 0;
}