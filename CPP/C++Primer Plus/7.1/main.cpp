#include<iostream>

using namespace std;

void simple();//函数原型

int main()
{
	cout << "main() will call the simple() function:\n";
	simple();//函数调用
	return 0;
}
void simple()//函数定义
{
	cout << "I'm but a simple function.\n";
}