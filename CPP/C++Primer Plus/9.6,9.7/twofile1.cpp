//��̬�����������ڲ�������
#include<iostream>

//�ⲿ��ȫ�ֱ���
int tom = 3;
int dick = 30;
//�ڲ������ԣ��ļ�������,��ǰ�ļ������к����ɼ�
static int harry = 300;

//��������
void remote_access();

int main()
{
	using namespace std;

	cout << "main reports the address:\n";
	cout << &tom << "=&tom," << &dick << "=&dick," << &harry << "=&harry\n";
	remote_access();
	return 0;
}