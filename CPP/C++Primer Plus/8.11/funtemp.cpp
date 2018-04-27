/*函数模板*/
#include<iostream>

//函数模板原型
template <class Any>//定义函数模板类型
//函数模板定义
void Swap(Any &a,Any &b);

int main()
{
	int i = 10;
	int j = 20;

	std::cout << "i,j = " << i << "," << j << std::endl;
	std::cout << "Using compiler-generated int swapper:\n";
	Swap(i,j);//生成void Swap(int &a,int &b);
	std::cout << "Now i,j = " << i << "," << j << std::endl;
	
	double x = 24.5;
	double y = 81.7;

	std::cout << "x,y = " << x << "," << y << std::endl;
	std::cout << "Using compiler-generated double swapper:\n";
	Swap(x,y);//生成void Swap(double &a,double &b);
	std::cout << "Now x,y = " << x << "," << y << std::endl;
	
	return 0;
}
template <typename Any>
void Swap(Any &a,Any &b)
{
	Any temp;
	 temp = a;
	 a = b;
	 b = temp;
}