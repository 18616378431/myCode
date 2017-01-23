//输出一个整数的8进制，10进制，16进制
#include<iostream>

using namespace std;

void tenToTwo(int _n);
void tenToEight(int n);
void tenToSixteen(int n);
void tenToX(int n,int x = 10);

int main()
{
	int n;
	
	cout << "Enter a number:";
	cin >> n;
	cout << oct << n << endl;
	cout << dec << n << endl;
	cout << hex << n << endl;
	
	cout << "Function implements convert:" << endl;
	tenToTwo(n);
	tenToEight(n);
	tenToSixteen(n);
	
	cout << "Common convert function:" << endl;
	tenToX(n,2);
	tenToX(n,8);
	tenToX(n,10);
	tenToX(n,16);
	
	
	return 0;
}
void tenToTwo(int n)
{
	int i = 0,j,arr[64];
	
	while(n > 0)
	{
		arr[i] = n % 2;
		n /= 2;
		i++;
	}
	for(j = i - 1;j >= 0;j--)
	{
		cout << arr[j];
	}
	cout << endl;
}
void tenToEight(int n)
{
	int i = 0,j,arr[64];
	
	while(n > 0)
	{
		arr[i] = n % 8;
		n /= 8;
		i++;
	}
	for(j = i - 1;j >= 0;j--)
	{
		cout << arr[j];
	}
	cout << endl;
}
void tenToSixteen(int n)
{
	int i = 0,j,arr[64];
	
	while(n > 0)
	{
		arr[i] = n % 16;
		n /= 16;
		i++;
	}
	for(j = i - 1;j >= 0;j--)
	{
		cout << arr[j];
	}
	cout << endl;
}
//n要转换的10进制整数,x要转换的进制数
void tenToX(int n,int x)
{
	int i = 0,j,arr[64];
	
	while(n > 0)
	{
		arr[i++] = n % x;
		n /= x;
	}
	for(j = i - 1;j >= 0;j--)
	{
		cout << arr[j];
	}
	cout << endl;
}

