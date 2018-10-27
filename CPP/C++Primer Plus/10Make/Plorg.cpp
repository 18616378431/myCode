//7.
#include<iostream>
#include<cstring>
#include"Plorg.h"

Plorg::Plorg()
{
	strncpy(name,"Plorga",MAX - 1);
	name[MAX - 1] = '\0';
	ci = 50;
}
Plorg::Plorg(char * my_name,int my_ci /* = 0 */)
{
	strncpy(name,my_name,MAX - 1);
	name[MAX - 1] = '\0';
	ci = my_ci;
}
void Plorg::modifyCI(int my_ci)
{
	ci = my_ci;
}
void Plorg::showPlorg()const
{
	std::cout << "name:" << name << ",CI:" << ci << std::endl;
}