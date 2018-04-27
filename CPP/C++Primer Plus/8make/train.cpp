////第八章复习题
//#include<iostream>
//
//using namespace std;
//
////3.函数重载
//void iquote(int n);
//void iquote(double x);
//void iquote(const char *str);
//
////4.结构体引用传参
//struct box{
//	char maker[40];
//	float height;
//	float width;
//	float length;
//	float volume;
//};
//void four(const struct box & b);
//void fourOne(struct box & b);
//
////5.默认参数/函数重载
////a 可以通过默认值和函数重载完成
////(1)默认参数
//double mass(double d,double v = 1.0);
////(2)函数重载
//double mass(double d,double v);
//double mass(double d);
////b 不能通过默认参数实现,可以通过函数重载实现,默认值必须从右到左
////函数重载
//void repeat(int n,const char * str);
//void repeat(const char * str);
////c 可以使用函数重载,参数类型不同
//int average(int m,int n);
//double average(double x,double y);
////d 不能完成,函数的特征标将相同,函数重载与参数列表有关,与返回值类型无关
//
////6.返回两个参数较大值的函数模板
//template <typename Any>
//Any get_max(const Any & x,const Any & y);
//
////7.模板具体化
////显式具体化模板函数
//template <> box get_max<box>(const box & b1,const box & b2);
//
//int main()
//{
//	int x = 3,y = 6;
//	cout << get_max(x,y) << endl;
//	return 0;
//}
////1.小型、非递归函数适用于inline内联函数
//
////2.a void song(char *name,int times = 1);
////	b 函数定义不需要声明默认值，只有原型需要声明默认值
////	c 为name提供默认值，需要给times添加默认值，默认值顺序需要从右至左
////	void song(char *name = "O.My Papa",int times = 1);
//
////3.函数重载
//void iquote(int n)
//{
//	cout << "\"" << n << "\"" << endl;
//}
//void iquote(double x)
//{
//	cout << "\"" << x << "\"" << endl;
//}
//void iquote(const char *str)
//{
//	cout << '"' << str << '"' << endl;
//}
//
////4.结构体引用传参
//void four(const struct box & b)
//{
//	cout << "maker:" << b.maker << endl;
//	cout << "height:" << b.height << endl;
//	cout << "width:" << b.width << endl;
//	cout << "length" << b.length << endl;
//	cout << "volume:" << b.volume << endl;
//}
//void fourOne(struct box & b)
//{
//	b.volume = b.height*b.width*b.length;
//}
//
////5. 判定以下情况是否可以使用默认值或函数重载完成(见声明处)
//
////6.返回两个参数较大值的函数模板
//template <typename Any>
//Any get_max(const Any & x,const Any & y)
//{
//	if(x > y)
//		return x;
//	else
//		return y;
//}
//
//
////7.函数模板 显式具体化,显式具体化之前要有相应的常规函数模板
//template <> box get_max<box>(const box & b1,const box & b2)
//{
//	return b1.volume > b2.volume?b1:b2;
//}