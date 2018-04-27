//静态持续变量，内部链接性
#include<iostream>

//外部，全局变量
int tom = 3;
int dick = 30;
//内部链接性，文件作用域,当前文件中所有函数可见
static int harry = 300;

//函数定义
void remote_access();

int main()
{
	using namespace std;

	cout << "main reports the address:\n";
	cout << &tom << "=&tom," << &dick << "=&dick," << &harry << "=&harry\n";
	remote_access();
	return 0;
}