////�ڰ��¸�ϰ��
//#include<iostream>
//
//using namespace std;
//
////3.��������
//void iquote(int n);
//void iquote(double x);
//void iquote(const char *str);
//
////4.�ṹ�����ô���
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
////5.Ĭ�ϲ���/��������
////a ����ͨ��Ĭ��ֵ�ͺ����������
////(1)Ĭ�ϲ���
//double mass(double d,double v = 1.0);
////(2)��������
//double mass(double d,double v);
//double mass(double d);
////b ����ͨ��Ĭ�ϲ���ʵ��,����ͨ����������ʵ��,Ĭ��ֵ������ҵ���
////��������
//void repeat(int n,const char * str);
//void repeat(const char * str);
////c ����ʹ�ú�������,�������Ͳ�ͬ
//int average(int m,int n);
//double average(double x,double y);
////d �������,�����������꽫��ͬ,��������������б��й�,�뷵��ֵ�����޹�
//
////6.�������������ϴ�ֵ�ĺ���ģ��
//template <typename Any>
//Any get_max(const Any & x,const Any & y);
//
////7.ģ����廯
////��ʽ���廯ģ�庯��
//template <> box get_max<box>(const box & b1,const box & b2);
//
//int main()
//{
//	int x = 3,y = 6;
//	cout << get_max(x,y) << endl;
//	return 0;
//}
////1.С�͡��ǵݹ麯��������inline��������
//
////2.a void song(char *name,int times = 1);
////	b �������岻��Ҫ����Ĭ��ֵ��ֻ��ԭ����Ҫ����Ĭ��ֵ
////	c Ϊname�ṩĬ��ֵ����Ҫ��times���Ĭ��ֵ��Ĭ��ֵ˳����Ҫ��������
////	void song(char *name = "O.My Papa",int times = 1);
//
////3.��������
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
////4.�ṹ�����ô���
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
////5. �ж���������Ƿ����ʹ��Ĭ��ֵ�����������(��������)
//
////6.�������������ϴ�ֵ�ĺ���ģ��
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
////7.����ģ�� ��ʽ���廯,��ʽ���廯֮ǰҪ����Ӧ�ĳ��溯��ģ��
//template <> box get_max<box>(const box & b1,const box & b2)
//{
//	return b1.volume > b2.volume?b1:b2;
//}