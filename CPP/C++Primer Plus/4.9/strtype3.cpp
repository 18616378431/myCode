#include<iostream>
#include<string>//string��
#include<cstring>//�ַ�������

using namespace std;

int main()
{
	char r1[20];
	char r2[20] = "123";
	string str1;
	string str2 = "qwer";

	//�ϲ�string������ַ�����
	str1 = str2;
	strcpy_s(r1, r2);
	//����string������ַ�����
	str1 += "pasdfg";
	strcat_s(r1, "yuio");
	//string����ĳ��Ⱥ�C����ַ����ĳ���
	int lenStr = str1.size();
	int lenCharArray = strlen(r1);
	cout << "The string " << str1 << " contains " << lenStr << " letters." << endl;
	cout << "The string " << r1 << " contains " << lenCharArray << " letters." << endl;
	return 0;
}