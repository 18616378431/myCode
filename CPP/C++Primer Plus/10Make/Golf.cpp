//3.
#include<iostream>
#include<cstring>
#include"Golf.h"

Golf::Golf()
{
	m_fullanme[0] = '\0';
	m_handicap = 0;
}
Golf::Golf(const char * fullname,const int handicap /* = 0 */)
{
	strncpy(m_fullanme,fullname,LEN - 1);
	m_fullanme[LEN - 1] = '\0';
	m_handicap = handicap;
}
int Golf::setGolf()
{
	char my_fullname[LEN];
	int my_handicap;

	std::cout << "Enter fullname:";
	std::cin.getline(my_fullname,LEN);
	if(strlen(my_fullname) == 0)
		return 0;
	std::cout << "Enter handicap:";
	std::cin >> my_handicap;
	while(std::cin.get() != '\n')
		continue;
	Golf g(my_fullname,my_handicap);
	*this = g;

	return 1;
}
void Golf::setHandicap(const int handicap)
{
	m_handicap = handicap;
}
void Golf::showGolf()const
{
	std::cout << "Fullname:" << m_fullanme << ",handicap:" << m_handicap << std::endl;
}