//17 Make Review

//1.iostream在C++I/O中的角色
//管理输入输出流及其缓冲区,该文件定义了用于管理输入和输出的类、常量和操纵符
//这些对象管理用于处理I/O的流和缓冲区
//该文件还创建了一些标准对象(cin、cout、cerr、clog及对应的宽字符对象)
//用于处理与每个程序相关联的输入输出流

//2.键入数字为何需要进行转换
//键盘输入生成一系列字符,输入121将生成三个字符,每个字符都由一个一字节的二进制码表示
//要将这个值存储为int型,则必须将这3个字符转换为121的二进制表示

//3.标准输出与标准错误的区别
//默认情况下,标准输出和标准错误都将信息发送给标准输出设备(显示器)
//在输出重定向到文件时,标准错误仍连接到屏幕,标准输出与文件相连

//4.为什么cout可以显示不同的C++类型
//因为ostream对象为每种内置类型都定义了重载的<<操作符,使得其与C++内置类型匹配
//operator<<(char &)

//5.输出方法的定义的哪一特征使得可以链式调用
//重载的operator<< ()操作符返回当前调用对象,ostream &,返回对象可以调用下一方法

//6.以基数前缀和十进制、八进制、十六进制显示数字

//7.以指定格式显示输入数据

//8.ct1 = 5 跳过空白 ct2 = 9 读取了上次输入留在输入缓冲区的换行符

//9.cin.ignore(80,'\n')和while(cin.get() != '\n')continue;的区别
//输入行超过80个字符ignore将不能正常工作,这种情况下它将跳过前80个字符

//#include <iostream>
//#include <iomanip>

//using namespace std;

//int main()
//{
	//6
	/*int x;
	cout << "Enter an number:";
	cin >> x;
	cout << setw(15) << "base ten"
		<< setw(15) << "base sixteen"
		<< setw(15) << "base eight" << endl;
	cout.setf(ios_base::showbase);
	cout << setw(15) << x << hex << setw(15) << x << setw(15) << oct << x << endl;*/

	//7
	//char name[20];
	//float wage;
	//float h;
	//cout << "Enter your name:";
	//cin.getline(name,20);
	//cout << "Enter your hourly wages:";
	//cin >> wage;
	//cout << "Enter number of hours worked:";
	//cin >> h;
	////cout.setf(ios_base::fixed,ios_base::floatfield);
	////cout.setf(ios_base::showpoint);
	////cout.setf(ios_base::right,ios_base::adjustfield);
	//cout << fixed << showpoint << right;

	//cout << "First format:\n";
	//cout << setw(20) << name << ":$" 
	//	<< setw(10) << setprecision(2) << wage << ":" 
	//	<< setw(10) << setprecision(1)  << h << endl;

	////cout.setf(ios_base::left,ios_base::adjustfield);
	//cout << left;
	//cout << "Second format:\n";
	//cout << setw(20) << name << ":$" << setw(10) << setprecision(2) << wage << ":" << setprecision(1) << setw(10) << h << endl;
	
	//8
	/*char ch;
	int ct1 = 0;
	cin >> ch;
	while(ch != 'q')
	{
		ct1++;
		cin >> ch;
	}

	int ct2 = 0;
	cin.get(ch);
	while(ch != 'q')
	{
		ct2++;
		cin.get(ch);
	}

	cout << "ct1 = " << ct1 << ";ct2 = " << ct2 << "\n";*/

//	return 0;
//}

