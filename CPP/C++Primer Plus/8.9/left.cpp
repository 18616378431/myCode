#include<iostream>
#include<cstring>//使用strlen函数

using namespace std;

const int ArSize = 80;

//函数形参默认值
char * left(const char * str,int n = 1);
//改进版
char * left_improve(const char * str,int n = 1);

int main()
{
	char simple[ArSize];
	cout << "Enter a string:";
	cin.get(simple,ArSize);

	char *ps = left(simple,4);
	cout << ps << endl;
	delete []ps;

	ps = left(simple);
	cout << ps << endl;
	delete []ps;

	ps = left_improve(simple,32767);
	cout << ps << endl;
	delete []ps;
	return 0;
}
char * left(const char * str,int n)
{
	if(n < 0)
		n = 0;
	char * p = new char[n+1];
	int i;
	for(i = 0;i < n && str[i];i++)
	{
		p[i] = str[i];
	}
	while(i <= n)
	{
		p[i++] = '\0';
	}
	return p;
}
//改进版
char * left_improve(const char * str,int n)
{
	int len = strlen(str);
	n = (n < len)?n:len;
	char * p = new char[n+1];
	int i;
	for(i = 0;i < n && str[i] != '\0';i++)
	{
		p[i] = str[i];
	}
	while(i <= n)
	{
		p[i++] = '\0';
	}
	return p;
}