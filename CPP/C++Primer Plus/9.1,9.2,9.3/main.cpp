//9.2 ֱ������ת��Ϊ������ �������ļ�
#include<iostream>
#include "coordin.h"

using namespace std;

int main(int argc,char *argv[])
{
	rect rplace;
	polar pplace;

	cout << "Enter the x,y values:";
	while(cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers(q to quit):";
	}
	return 0;
}