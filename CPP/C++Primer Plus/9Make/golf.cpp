#include<iostream>
#include<cstring>
#include"golf.h"

//第一个版本
void setgolf(golf & g,char * name,int hc)
{
	strcpy(g.fullname,name);
	g.handicap = hc;
}
//重载版本
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
//重置handicap为新值
void handicap(golf & g,int hc)
{
	g.handicap = hc;
}
//显式结构体内容
void showgolf(const golf & g)
{
	std::cout << "Fullname is " << g.fullname << " and level is " << g.handicap << std::endl;
}