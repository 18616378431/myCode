//review

//1.
//a.friend class clasp;
//b.需要向前声明以便编译器能够解释void snip(muff &);
//class muff;
//class cuff
//{
//public:
//	void snip(muff &){...}
//	...
//};
//class muff
//{
//	friend void cuff::snip(muff &);
//	...
//};
//c.需要一个向前声明cuff,以便编译器可以理解cuff::snip(muff &);
//	编译器需要muff的一个向前声明,以便可以理解snip(muff &);
//class cuff;
//class muff
//{
//	friend void cuff::snip(muff &);
//};
//class cuff
//{
//public:
//	friend void snip(muff &);
//};

//2.不能 为使类A拥有一个本身为B的成员函数的友元,B的声明必须位于A的声明之前
//一个正向声明是不够的,这个声明可以告诉A:B是一个类,但它不能指出类成员的名称
//如果B拥有一个本身是A成员函数的友元,则A的声明必须在B声明之前,这两个要求是互斥的

//3.访问该嵌套类是唯一方法的是通过类公有接口,这意味着Sauce只能通过构造函数创建
//	其他成员在默认情况下是私有的

//4.throw终止程序并执行堆栈解退,直到找到匹配的catch块
//return立即终止程序,并将控制权移交给上层调用函数,继续执行调用函数后面的语句
//假设f1()调用函数f2(),f2()中的返回语句导致程序执行f1()中调用函数f2()后面的语句
//throw语句导致程序沿函数的调用序列回溯,直到找到直接或间接包含对f2()调用的try块为止
//它可能在f1()、调用f1()的函数、或其他函数中
//找到这样的try块将执行其匹配的catch块,而不是函数调用后的语句

//5.按派生顺序放置catch块,最后放基类,子孙->祖先

//6.
//#1pg指向Superb或其派生类,[ps == dynamic_cast<Superb *>(*pg)]if表达式为true
//#2仅当pg指向Superb时,[typeif(*pg) == typeid(Superb)]if表达式为true

//7.dynamic_cast操作符允许沿类层次结构向上转换
//static_cast操作符允许向上和向下转换,还允许枚举类型和整型以及数值类型之间的转换
