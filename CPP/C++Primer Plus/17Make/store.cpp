//7. function object
#include "store.h"

//overload operator ()
void store::operator() (const std::string & s)
{
	std::size_t len = s.size();
	o.write((char *)&len,sizeof(len));
	o.write((char *)s.data(),len);
}