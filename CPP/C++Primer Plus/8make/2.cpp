////结构体引用,函数默认值,函数原型可定义参数默认值,原型不可带默认值
//#include<iostream>
//#include<cstring>//c字符串函数库
//
//using namespace std;
//
//const int SIZE = 40;
//
//struct CandyBar{
//	char maker[SIZE];
//	double weight;
//	int hot;
//};
//
//void set_value(struct CandyBar & c,const char * m = "Millennium",const double w = 2.85,const int h = 350);
//
//void show_value(const struct CandyBar & c);
//
//int main()
//{
//	struct CandyBar c;
//	
//	set_value(c);
//	show_value(c);
//
//	char name[30];
//	double weight;
//	int hot;
//
//	cin.getline(name,30);
//	cin >> weight >> hot;
//	set_value(c,name,weight,hot);
//	show_value(c);
//	return 0;
//}
//void set_value(struct CandyBar & c,const char * m,const double w,const int h)
//{
//	strcpy(c.maker,m);
//	c.weight = w;
//	c.hot = h;
//}
//void show_value(const struct CandyBar & c)
//{
//	cout << "maker:" << c.maker << endl;
//	cout << "weight:" << c.weight << endl;
//	cout << "hot:" << c.hot << endl;
//}