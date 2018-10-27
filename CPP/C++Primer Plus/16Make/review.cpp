//review
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <memory>

using namespace std;

//3.
string & StringToUpper(string & s);

//int main()
//{
//
//	//3.
//	string test3 = "abcedf";
//	cout << StringToUpper(test3) << endl;
//
//	return 0;
//}

//1.不再需要显式复制构造函数、=操作符、析构函数,string对象提供了自己的内存管理
class RQ1
{
private:
	string st;
public:
	RQ1():st(""){}
	RQ1(const char * s):st(s){}
	~RQ1(){}

};
//2.(1)重载了+操作符,可以将两个字符串相加,得到两个字符串拼接的结果
//  (2)重载了赋值操作符,可以将一个字符串赋值给另一个
//	(3)对象过期将自动执行析构函数,不需要手动管理内存
//	(4)string对象提供了自己的内存管理,不需要担心字符串超出存储容量

//3.
string & StringToUpper(string & s)
{
	/*for(int i = 0;i < s.size();i++)
		s[i] = toupper(s[i]);*/

	transform(s.begin(),s.end(),s.begin(),toupper);
	
	return s;
}
//4.错误使用auto_ptr
//	(1)auto_ptr<int> pia(new int[20]);不能将数组作为参数,因为其析构函数为delete ptr版本
//	(2)auto_ptr<string> (new string);缺少变量名称
//	(3)int rigue = 7;auto_ptr<int> pr(&rigue);不能将栈变量初始化为auto_ptr,且不能执行delete操作,内存未使用new进行分配
//	(4)auto_ptr dlb(new double);未传递模板参数

//5.堆栈只能从栈顶弹出元素,要取出栈中间或底部的元素将浪费很多操作

//6.set容器是有序唯一的集合,只存储每个值的一个拷贝,五个5分将只存储一个5分

//7.使用迭代器使得能够使用接口类似于指针的对象遍历不以数组方式组织的数据,双向链表中的数据

//8.STL方法使得可以将STL函数用于指向常规数组的常规指针以及指向STL容器类的迭代器,提高了通用性

//9.vector比常规数组方便的例子
//	(1)动态扩容
//	(2)可以将vecotr对象赋给另一个
//	(3)vector管理自己的内存
//	(4)使用at()方法可以自动检查边界

//10.使用list替代vecrtor来储存数据将会出现哪些问题
//	(1)push_back、size和random_shuffle要求随机访问迭代器,list只有双向迭代器
//	(2)可以使用list模板的sort函数来代替通用sort函数,没有与random_shuffle等效的成员函数
//		可以将list中的元素复制到vector中并random_shuffle,然后将矢量中的值复制回list中
