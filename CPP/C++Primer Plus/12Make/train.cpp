#include <iostream>

//int main()
//{
//	return 0;
//}
//1.类构造函数可能出现的问题
//a.没有初始化类成员
//b.将类指针赋值为其他指针
//c.没有为类指针成员分配内存

//2.类成员是个指针使用new分配内存可能出现的问题
//a.没有在析构函数释放成员指针指向的内存
//b.没有显式声明类复制构造函数,造成成员浅复制
//c.没有显式重载赋值操作符,造成类赋值时进行浅复制

//3.如果没有显式地提供类方法,编译器将默认生成哪些方法
//编译器将生成默认构造函数，该函数不执行任何操作
//复制构造函数,调用复制构造函数时仅进行浅复制,仅复制成员的值
//赋值操作符,进行浅复制
//析构函数
//地址操作符,隐式地址操作符将返回对象地址

//4.找出下述类的错误并修正
//a.char指针声明为变长数组
//b.公有方法未在public声明下
//c.函数参数值得构造函数参数未声明为const类型,可能改变原数据
//d.重载<<操作符未声明为友元
//e.类外实现的类方法未使用作用域解析操作符::
//f.为字符串指针成员分配内存时未为末尾的字符串结束符分配内存,'\0'
//g.成员指针仅进行的浅复制,复制指针的值
//h.未将方法设置为公有的
#include <iostream>
#include <cstring>

class niffty
{
private:
	char * personality;
	int talents;
public:
	niffty();
	niffty(const char * s);
	friend std::ostream & operator<< (std::ostream & os,const niffty & n);
};
niffty::niffty()
{
	personality = NULL;
	talents = 0;
}
niffty::niffty(const char * s)
{
	personality = new char[strlen(s) + 1];
	std::strcpy(personality,s);
	talents = 0;
}
std::ostream & operator<< (std::ostream & os,const niffty & n)
{
	std::cout << n.personality << "\n" << n.talents << std:: endl;
	return os;
}
//5.下面的类声明将调用哪些方法
class Golfer
{
private:
	char * fullname;
	int games;
	int * scores;
public:
	Golfer();
	Golfer(const char * name,int g = 0);
	Golfer(const Golfer & g);
	~Golfer();
};
//a.Golfer nancy;//Golfer();
//b.Golfer lulu("Little Lulu");//Golfer(const char * name,int g = 0);
//c.Golfer roy("Roy Bobbs",12);//Golfer(const char * name,int g = 0);
//d.Golfer * par = new Golfer;//Golfer();
//e.Golfer next = lulu;//Golfer(const Golfer & g);
//f.Golfer hazzard = "Weed Thwacker";//Golfer(const char * name,int g = 0);
//g.*par = nancy;//默认赋值操作符
//h.nancy = "Nancy Putter";//Golfer(const char * name,int g = 0);then 默认赋值操作符
