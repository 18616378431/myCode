#include<iostream>

//�������������ļ��ж����ȫ�ֱ���
extern int tom;
//���������ļ������ȫ��dick����
static int dick = 10;
//��file1�б�����
int harry = 200;

void remote_access()
{
	using namespace std;
	
	cout << "remote_access reports the address:\n";
	cout << &tom << "=&tom," << &dick << "=&dick," << &harry << "=&harry\n";
}