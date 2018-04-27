#include<iostream>

//引用声明其他文件中定义的全局变量
extern int tom;
//隐藏其他文件定义的全局dick变量
static int dick = 10;
//在file1中被隐藏
int harry = 200;

void remote_access()
{
	using namespace std;
	
	cout << "remote_access reports the address:\n";
	cout << &tom << "=&tom," << &dick << "=&dick," << &harry << "=&harry\n";
}