////4.�������ء�Ĭ��ֵ,string����std�����ռ��
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
////��stringy�ṹ���str��Ա��ֵΪstr,�����ó���ct
//void  set(struct stringy & ss,const char * str);
////��ʽ�ṹ������ָ������,��ʹ�ú���Ĭ��ֵ
//void show(const struct stringy & ss,int n = 1);
////��������,��ʽ�ַ����汾
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