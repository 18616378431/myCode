////4.函数重载、默认值,string类是std命名空间的
//#include<iostream>
//#include<cstring>//strcpy(),strlen()
//
//using namespace std;
//
//struct stringy{
//	char * str;
//	int ct;
//};
//
////将stringy结构体的str成员赋值为str,并设置长度ct
//void  set(struct stringy & ss,const char * str);
////显式结构体内容指定次数,并使用函数默认值
//void show(const struct stringy & ss,int n = 1);
////函数重载,显式字符串版本
//void show(const char * str,int n = 1);
//
//int main()
//{
//	struct stringy beany;
//	char testing[] = "Reality isn't what it used to be.";
//
//	set(beany,testing);
//	show(beany);
//	show(beany,2);
//
//	testing[0] = 'D';
//	testing[1] = 'u';
//	show(testing);
//	show(testing,3);
//	return 0;
//}
//void  set(struct stringy & ss,const char * str)
//{
//	int length = strlen(str);
//	ss.str = new char[length + 1];
//	strcpy(ss.str,str);
//	ss.ct = length;
//}
//void show(const struct stringy & ss,int n)
//{
//	for(int i = 0;i < n;i++)
//		cout << ss.str << endl;
//}
//void show(const char * str,int n)
//{
//	for(int i = 0;i < n;i++)
//		cout << str << endl;
//}