//�ⲿ����
#include<iostream>

using namespace std;

//external variable
double warming = 0.3;

void update(double dt);
void local();

int main()
{
	cout << "Global warming is " << warming << " degrees.\n";
	update(0.1);
	cout << "Global warming is " << warming << " degrees.\n";
	local();
	cout << "Global warming is " << warming << " degrees.\n";
	return 0;
}
//ϥ��ȫ�ֱ���
void update(double dt)
{
	extern double warming;
	warming += dt;
	cout << "Updating global warming to " << warming << " degrees.\n";
}
//ʹ�ñ��ر�������ȫ�ֱ���
void local()
{
	double warming = 0.8;

	cout << "Local warming is " << warming << " degrees.\n";
	cout << "But global warming is " << ::warming << " degrees.\n";
}