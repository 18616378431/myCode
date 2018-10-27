//13.2 基类实现
#include "tabtenn0.h"
#include <iostream>
#include <cstring>

TableTennisPlayer::TableTennisPlayer(const char * fn /* =  */,const char * ln /* =  */,bool ht /* = false */)
{
	std::strncpy(firstname,fn,LIM - 1);
	firstname[LIM - 1] = '\0';
	std::strncpy(lastname,ln,LIM - 1);
	lastname[LIM - 1] = '\0';
	hasTable = ht;
}
void TableTennisPlayer::Name()const
{
	std::cout << lastname << "," << firstname;
}