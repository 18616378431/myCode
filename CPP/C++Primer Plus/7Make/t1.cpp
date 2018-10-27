////第七章复习题
//#include<iostream>
//
//using namespace std;
////1.原型、定义、调用
////2.
//void igor();
//float tofu(int n);
//double mpg(double a,double b);
//long summation(long arr[],int n);
//double doctor(const char *str);
//struct boos{
//	int a;
//};
//void ofcourse(boos b);
//struct map{
//	int a;
//};
//char *plot(map *m);
//
////3.
//void revalue(int arr[],int size,int k);
//
////4.
//void revalueA(int *begin,const int *end,int k);
//
////5.
//double getMax(const double *arr,int size);
//
////6.cosnt用于指针防止修改原始数据,函数传递普通变量将按值传递,函数使用原变量的拷贝
//
////7.char *,char str[SIZE],"abc"
//
////8.
//int replace(char *str,char c1,char c2);
//
////9.*"pizza","pizza"为第一个元素的地址*"pizza"为第一个元素的值p,
////"taco"为第一个元素的地址,"taco"[2]等价于指向"taco"的指针后移两位,p+2,结果为c,
////字符串常量的行为与数组相同
//
////10.void ttt(gliz a);按值传递,传递结构名,void ttt(gliz *pg);传递地址,传递结构的地址&gliz
////按值传递使用结构的拷贝,保护原始数据,占用空间大,使用常规结构成员操作符.
////传递地址,可修改原始结构,不需要分配额外的空间,使用间接操作符->,使用const可防止修改原始数据
//
////11.
//int getcharacters(const char *s);
//int judge(int (*pf)(const char *strt));
//
//int main()
//{
//	int arr[5] = {1,2,3,4,5};
//	double arr1[5] = {1.1,2.2,3.3,4.4,5.5};
//	char str[100] = "abcdefgkkllggg";
//
//	revalue(arr,5,11);
//	revalueA(arr,arr+5,0);
//	double max = getMax(arr1,5);
//	replace(str,'g','m');
//
//	judge(getcharacters);
//	return 0;
//}
////3.
//void revalue(int arr[],int size,int k)
//{
//	for(int i = 0;i < size;i++)
//	{
//		arr[i] = k;
//	}
//}
////4.
//void revalueA(int *begin,const int *end,int k)
//{
//	int *p = begin;
//
//	while(p != end)
//	{
//		*p = k;
//		p++;
//	}
//}
////5.
//double getMax(const double *arr,int size)
//{
//	double max = arr[0];
//
//	for(int i = 1;i < size;i++)
//	{
//		if(arr[i] > max)
//			max = arr[i];
//	}
//	return max;
//}
////8.
//int replace(char *str,char c1,char c2)
//{
//	int count = 0;
//	while(*str != '\0')
//	{
//		if(*str == c1)
//		{
//			*str = c2;
//			count++;
//		}
//		str++;
//	}
//	return count;
//}
////11.函数指针
//int getcharacters(const char *s)
//{
//	int count = 0;
//	
//	while(*s != '\0')
//	{
//		count++;
//		s++;
//	}
//	return count;
//}
//int judge(int (*pf)(const char *strt))
//{
//	int length = (*pf)("abcdefg");
//	return length;
//}