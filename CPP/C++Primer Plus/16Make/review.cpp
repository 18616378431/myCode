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

//1.������Ҫ��ʽ���ƹ��캯����=����������������,string�����ṩ���Լ����ڴ����
class RQ1
{
private:
	string st;
public:
	RQ1():st(""){}
	RQ1(const char * s):st(s){}
	~RQ1(){}

};
//2.(1)������+������,���Խ������ַ������,�õ������ַ���ƴ�ӵĽ��
//  (2)�����˸�ֵ������,���Խ�һ���ַ�����ֵ����һ��
//	(3)������ڽ��Զ�ִ����������,����Ҫ�ֶ������ڴ�
//	(4)string�����ṩ���Լ����ڴ����,����Ҫ�����ַ��������洢����

//3.
string & StringToUpper(string & s)
{
	/*for(int i = 0;i < s.size();i++)
		s[i] = toupper(s[i]);*/

	transform(s.begin(),s.end(),s.begin(),toupper);
	
	return s;
}
//4.����ʹ��auto_ptr
//	(1)auto_ptr<int> pia(new int[20]);���ܽ�������Ϊ����,��Ϊ����������Ϊdelete ptr�汾
//	(2)auto_ptr<string> (new string);ȱ�ٱ�������
//	(3)int rigue = 7;auto_ptr<int> pr(&rigue);���ܽ�ջ������ʼ��Ϊauto_ptr,�Ҳ���ִ��delete����,�ڴ�δʹ��new���з���
//	(4)auto_ptr dlb(new double);δ����ģ�����

//5.��ջֻ�ܴ�ջ������Ԫ��,Ҫȡ��ջ�м��ײ���Ԫ�ؽ��˷Ѻܶ����

//6.set����������Ψһ�ļ���,ֻ�洢ÿ��ֵ��һ������,���5�ֽ�ֻ�洢һ��5��

//7.ʹ�õ�����ʹ���ܹ�ʹ�ýӿ�������ָ��Ķ�������������鷽ʽ��֯������,˫�������е�����

//8.STL����ʹ�ÿ��Խ�STL��������ָ�򳣹�����ĳ���ָ���Լ�ָ��STL������ĵ�����,�����ͨ����

//9.vector�ȳ������鷽�������
//	(1)��̬����
//	(2)���Խ�vecotr���󸳸���һ��
//	(3)vector�����Լ����ڴ�
//	(4)ʹ��at()���������Զ����߽�

//10.ʹ��list���vecrtor���������ݽ��������Щ����
//	(1)push_back��size��random_shuffleҪ��������ʵ�����,listֻ��˫�������
//	(2)����ʹ��listģ���sort����������ͨ��sort����,û����random_shuffle��Ч�ĳ�Ա����
//		���Խ�list�е�Ԫ�ظ��Ƶ�vector�в�random_shuffle,Ȼ��ʸ���е�ֵ���ƻ�list��
