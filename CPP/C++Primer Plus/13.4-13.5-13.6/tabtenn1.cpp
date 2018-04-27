//13.5 基类 派生类实现
#include "tabtenn1.h"
#include <iostream>
#include <cstring>

//TableTennisPlayer implements
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
//RatedPlayer implements
RatedPlayer::RatedPlayer(unsigned int r /* = 0 */,const char * fn /* =  */,
						 const char * ln /* =  */,bool ht /* = false */):
						TableTennisPlayer(fn,ln,ht)
{
	rating = r;
}
RatedPlayer::RatedPlayer(unsigned int r,const TableTennisPlayer & tp):
					TableTennisPlayer(tp),rating(r)
{

}
