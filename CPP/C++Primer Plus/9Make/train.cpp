//#include<iostream>
//
//void three();
//void four();
//static int average(int a,int b);
//void call();
//
////6
//void six();
//void other();
//void another();
//
//int x = 10;
//int y;
//
////7.
//void seven();
//namespace n1
//{
//	int m = 1;
//}
//namespace n2
//{
//	int m = 2;
//}
//void other1();
//
//
//
//int main()
//{
//	//3.
//	three();
//	//4.
//	four();
//	//5.
//	std::cout << "File1 average = " << average(3,6) << std::endl;
//	call();
//	//6.
//	six();
//	//7.
//	seven();
//	return 0;
//}
////1.a.自动变量
////b.静态全局变量链接性为外部,在另一个文件中使用extern声明
////c.内部链接的静态变量,文件作用域static,或在未命名的名称空间中声明的名称
////d.无链接性的局部静态变量,代码块作用域static
//
////2.(1)using声明只导入的声明的名称,using编译指令导入了名称空间中全部的名称
////	(2)using声明使得名称空间中的单个名称可用,其作用域与using所在声明区域相同,
////		using编译指令使名称空间中的所有名称可用
////	(3)使用using编译指令,就像在包含using声明和名称空间本身最小的声明区域中声明了这些名称
//
////3.不使用using声明和using编译指令
//void three()
//{
//	double x;
//	std::cout << "Enter value:";
//	while(!(std::cin >> x))
//	{
//		std::cout << "Bad input,Please enter a number:";
//		std::cin.clear();
//		while(std::cin.get() != '\n')
//			continue;
//	}
//	std::cout << "Value = " <<  x << std::endl;
//}
////4.不使用using编译指令,使用using声明
//void four()
//{
//	using std::cout;
//	using std::cin;
//	using std::endl;
//
//	double x;
//
//	cout << "Enter value:";
//	while(!(cin >> x))
//	{
//		cout << "Bad input,Please enter a number:";
//		cin.clear();
//		while(cin.get() != '\n')
//			continue;
//	}
//	cout << "Value = " << x << endl;
//}
////5.一个文件调用返回int,另一个文件调用返回double
////函数默认作用域为链接性外部extern,使用静态函数内部链接性,文件作用域
////或每个文件都在未命名的名称空间定义一个返回不同类型的函数
//static int average(int a,int b)
//{
//	return (a + b)/2;
//}
////6.静态全局外部链接变量作用域,局部变量覆盖全局变量,未命名名称空间作用域为文件
//void six()
//{
//	using namespace std;
//
//	cout << x << endl;
//	{
//		int x = 4;//代码块作用域,覆盖全局变量
//		cout << x << endl;
//		cout << y << endl;//未初始化的全局变量,默认初始化为0
//	}
//	other();
//	another();
//}
//void other()
//{
//	using namespace std;
//
//	int y = 1;//局部变量覆盖同名全局变量
//	cout << "Other : " << x << "," << y << endl;
//}
////7.作用域解析操作符访问名称空间中的名称
//void seven()
//{
//	using namespace std;
//	using namespace n1;
//
//	cout << m << endl;
//	{
//		int m = 4;//局部覆盖全局
//		cout << m << "," << n1::m << "," << n2::m << endl;
//	}
//	using n2::m;//n2命名空间中的名称覆盖了前面声明的名称空间中的名称
//	cout << m << endl;
//	other1();
//}
//void other1()
//{
//	using namespace std;
//	using namespace n2;
//
//	cout << m << endl;
//	{
//		int m = 4;
//		cout << m << "," << n1::m << "," << n2::m << endl;
//	}
//	using n2::m;
//	cout << m << endl;
//}