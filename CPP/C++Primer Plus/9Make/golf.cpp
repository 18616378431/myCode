#include<iostream>
#include<cstring>
#include"golf.h"

//��һ���汾
void setgolf(golf & g,char * name,int hc)
{
	strcpy(g.fullname,name);
	g.handicap = hc;
}
//���ذ汾
int setgolf(golf & g)
{
	std::cout << "Enter fullname:";
	std::cin.getline(g.fullname,LEN);
	if(strlen(g.fullname) == 0)
		return 0;
	std::cout << "Enter handicap:";
	std::cin >> g.handicap;
	while(std::cin.get() != '\n')
		continue;
	return 1;
}
//����handicapΪ��ֵ
void handicap(golf & g,int hc)
{
	g.handicap = hc;
}
//��ʽ�ṹ������
void showgolf(const golf & g)
{
	std::cout << "Fullname is " << g.fullname << " and level is " << g.handicap << std::endl;
}