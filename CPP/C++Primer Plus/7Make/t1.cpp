////�����¸�ϰ��
//#include<iostream>
//
//using namespace std;
////1.ԭ�͡����塢����
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
////6.cosnt����ָ���ֹ�޸�ԭʼ����,����������ͨ��������ֵ����,����ʹ��ԭ�����Ŀ���
//
////7.char *,char str[SIZE],"abc"
//
////8.
//int replace(char *str,char c1,char c2);
//
////9.*"pizza","pizza"Ϊ��һ��Ԫ�صĵ�ַ*"pizza"Ϊ��һ��Ԫ�ص�ֵp,
////"taco"Ϊ��һ��Ԫ�صĵ�ַ,"taco"[2]�ȼ���ָ��"taco"��ָ�������λ,p+2,���Ϊc,
////�ַ�����������Ϊ��������ͬ
//
////10.void ttt(gliz a);��ֵ����,���ݽṹ��,void ttt(gliz *pg);���ݵ�ַ,���ݽṹ�ĵ�ַ&gliz
////��ֵ����ʹ�ýṹ�Ŀ���,����ԭʼ����,ռ�ÿռ��,ʹ�ó���ṹ��Ա������.
////���ݵ�ַ,���޸�ԭʼ�ṹ,����Ҫ�������Ŀռ�,ʹ�ü�Ӳ�����->,ʹ��const�ɷ�ֹ�޸�ԭʼ����
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
////11.����ָ��
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