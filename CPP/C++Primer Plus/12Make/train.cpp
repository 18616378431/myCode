#include <iostream>

//int main()
//{
//	return 0;
//}
//1.�๹�캯�����ܳ��ֵ�����
//a.û�г�ʼ�����Ա
//b.����ָ�븳ֵΪ����ָ��
//c.û��Ϊ��ָ���Ա�����ڴ�

//2.���Ա�Ǹ�ָ��ʹ��new�����ڴ���ܳ��ֵ�����
//a.û�������������ͷų�Աָ��ָ����ڴ�
//b.û����ʽ�����ิ�ƹ��캯��,��ɳ�Աǳ����
//c.û����ʽ���ظ�ֵ������,����ำֵʱ����ǳ����

//3.���û����ʽ���ṩ�෽��,��������Ĭ��������Щ����
//������������Ĭ�Ϲ��캯�����ú�����ִ���κβ���
//���ƹ��캯��,���ø��ƹ��캯��ʱ������ǳ����,�����Ƴ�Ա��ֵ
//��ֵ������,����ǳ����
//��������
//��ַ������,��ʽ��ַ�����������ض����ַ

//4.�ҳ�������Ĵ�������
//a.charָ������Ϊ�䳤����
//b.���з���δ��public������
//c.��������ֵ�ù��캯������δ����Ϊconst����,���ܸı�ԭ����
//d.����<<������δ����Ϊ��Ԫ
//e.����ʵ�ֵ��෽��δʹ�����������������::
//f.Ϊ�ַ���ָ���Ա�����ڴ�ʱδΪĩβ���ַ��������������ڴ�,'\0'
//g.��Աָ������е�ǳ����,����ָ���ֵ
//h.δ����������Ϊ���е�
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
//5.�������������������Щ����
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
//g.*par = nancy;//Ĭ�ϸ�ֵ������
//h.nancy = "Nancy Putter";//Golfer(const char * name,int g = 0);then Ĭ�ϸ�ֵ������
